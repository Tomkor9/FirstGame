#include "Elog.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

Elog::Elog(){
	time_start = std::chrono::duration<double>
		(std::chrono::steady_clock::now().time_since_epoch()).count();
}

void Elog::status::print(std::ostream& stream) const{
	switch (execution_status)
	{
		case 0: stream << "[i] "; break;    //good
		case 1: stream << "[E] "; break;    //error
		case 2: stream << "[!] "; break;    //warning
		default: stream << "[?] "; break;   //other
	}
	stream << std::setprecision(3) << elapsed_seconds << "s: ";
	stream << log_text << "\n";
}

void Elog::logSetMaxNotifications(unsigned int max) {
	maxNotifications = max;
}

void Elog::logInfo(char* info, unsigned char state) {

	status s;
	s.log_text = info;
	s.execution_status = state;

	//counting elapsed time:
	s.elapsed_seconds = std::chrono::duration<double>
		(std::chrono::steady_clock::now().time_since_epoch()).count() - time_start;
	
	s.print(std::cout);
	if (log_register.size() <= maxNotifications)
		log_register.push_back(s);
	else
		logClear();
}

void Elog::logClear() {
	log_register.clear();
}

void Elog::logPrint(double start, double finish) {
	if(!log_register.empty())
		if (start != 0.0 || finish != 0.0) {
			for (const auto& x : log_register)
				if(x.elapsed_seconds >= start && x.elapsed_seconds <= finish)
					x.print(std::cout);
		}
		else
			for (const auto& x : log_register)
				x.print(std::cout);
}

void Elog::logExport(char* dir) {
	std::ofstream file(dir);
	if (!file.is_open())
		throw std::runtime_error("unable to open file");
	
	if (!log_register.empty()) {
		time_t result = time(0);
		file << ctime(&result) << "\n";
		for (const auto& x : log_register)
			x.print(file);
	}
}
#ifndef FIRSTGAME_ELOG
#define FIRSTGAME_ELOG
/* engine/error log */

#include <string>
#include <deque>
#include <chrono>

class Elog {
private:
	unsigned int maxNotifications = 500;
	double time_start;
	struct status {
		std::string log_text;
		unsigned char execution_status;
		double elapsed_seconds;
		void print(std::ostream& stream) const;
	};
	std::deque<status> log_register;

public:
	Elog();                                                 //starts timer count
	void logInfo(char* info, unsigned char state);          //adds log instance to register and prints it in console
	void logPrint(double start = 0.0, double finish = 0.0); //prints logs
	void logClear();                                        //clears all logs
	void logExport(char* dir);                              //exports logs to file
	void logSetMaxNotifications(unsigned int max);
};

#endif // !FIRSTGAME_ELOG
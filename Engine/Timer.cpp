#include "Timer.hpp"
#include <iostream>


Measure_ms::Measure_ms() {
	start = std::chrono::high_resolution_clock::now();
}

Measure_ms::~Measure_ms() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;

	std::cout << duration.count() * 1000.0f << "ms\n";
}
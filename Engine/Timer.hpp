#ifndef FIRSTGAME_TIMER
#define FIRSTGAME_TIMER
#include <chrono>

//This struct shows timeof execution in ms upon destruction
//simply insert " Measure_ms time; " in code to see value in the console
//Warning: it slows performance down!
struct Measure_ms {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Measure_ms();
	~Measure_ms();
};



#endif //FIRSTGAME_TIMER

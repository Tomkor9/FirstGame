//================== ENTRY OF PROGRAM ==================

#include "../Engine/Engine.hpp"
#include "../Graphics/Sprite.hpp"
//#include "../Engine/Timer.hpp"

#include <iostream>

int main()
{
	//ENGINE AND WINDOW
	Engine engine;
	engine.initialize("Game!"); 
	
	//SPRITES INITIALIZATION:
	Sprite test = Sprite("Assets/F22.png", 0, 0);

	//GAME LOOP
	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 1;

	unsigned long next_game_tick = engine.get_current_time();
	int loops;

	bool game_is_running = true;
	while (game_is_running) {
		loops = 0;
		while (engine.get_current_time() > next_game_tick && loops < MAX_FRAMESKIP)
		{

			engine.Update();

			/* --- assetes update: --- */
			test.Update();



			//---------------------------
			engine.BeginRender();

			/* --- assetes render: --- */
			test.Render();



			//---------------------------
			engine.EndRender();
			next_game_tick += SKIP_TICKS;
			loops++;
		}
	}
	std::cin.get();
    return 0;
}


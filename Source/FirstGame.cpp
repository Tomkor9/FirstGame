//================== ENTRY OF PROGRAM ==================

#include "../Engine/Engine.hpp"
#include "../Graphics/Sprite.hpp"
#include "../Engine/IO/Mouse.hpp"
//#include "../Engine/Timer.hpp"

#include <iostream>

int main()
{
	//ENGINE AND WINDOW
	Engine engine;
	engine.initialize("Game!"); 
	
	//SPRITES INITIALIZATION:
	Sprite plane = Sprite("Assets/F22.png", 0, 0);
	Sprite boom = Sprite("Assets/lel.png", 100, 100);

	//GAME LOOP
	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 15;

	unsigned long next_game_tick = glfwGetTime() * 1000;
	int loops;

	bool game_is_running = true;
	while (game_is_running) {
		loops = 0;
		while ((glfwGetTime() * 1000) > next_game_tick && loops < MAX_FRAMESKIP)
		{
			engine.Update();
			/* --- assetes update: --- */
			boom.Update();
			plane.Update();
			plane.SetPos(Mouse::getMouseX(), Mouse::getMouseY());   //mouse picture hover


			//---------------------------
			engine.BeginRender();
			/* --- assetes render: --- */
			boom.Render();
			plane.Render();


			//---------------------------
			engine.EndRender();
			next_game_tick += SKIP_TICKS;
			loops++;
		}
	}
	std::cin.get();
    return 0;
}


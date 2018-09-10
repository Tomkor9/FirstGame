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
	Sprite sky = Sprite("Assets/sky.jpg", 0, 0);
	Sprite plane = Sprite("Assets/F22.png", 0, 0);
	Sprite cloud = Sprite("Assets/cloud.png");
	Sprite lel = Sprite("Assets/lel.png", 700, 200, 180);

	//GAME LOOP
	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 15;

	unsigned long next_game_tick = glfwGetTime() * 1000;
	int loops;
	bool game_is_running = true;

	//TESTING
	int speed = 0;  //cloud speed
	
	/* --- static assetes actions: --- */
	sky.Update();
	lel.Update();
	//---------------------------

	while (game_is_running) {
		loops = 0;
		while ((glfwGetTime() * 1000) > next_game_tick && loops < MAX_FRAMESKIP)
		{
			engine.Update();
			/* --- dynamic assetes actions: --- */
			
			cloud.Update();
			plane.Update();	
			plane.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());   //mouse picture hover
			if (speed < 1800)
				cloud.SetPos(1100 - (speed++), 400);
			else
				speed = 0;

			//---------------------------
			engine.BeginRender();
			/* --- assetes render: --- */
			
			sky.Render();
			lel.Render();
			plane.Render();
			cloud.Render();


			//---------------------------
			engine.EndRender();
			next_game_tick += SKIP_TICKS;
			loops++;
		}
	}
	std::cin.get();
    return 0;
}

/* Usefull functions */
/*
	plane.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());   //mouse picture hover

*/
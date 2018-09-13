//================== ENTRY OF PROGRAM ==================

#include "../Engine/Engine.hpp"
#include "../Graphics/Sprite.hpp"
#include "../Engine/IO/Mouse.hpp"
#include "../Engine/IO/Keyboard.hpp"
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
	Sprite cloud1 = Sprite("Assets/cloud.png", 800, -300);
	Sprite cloud2 = Sprite("Assets/cloud.png", 3000, 200, 180, 5, 5);
	Sprite lel = Sprite("Assets/lel.png", 700, 200, 180);

	//GAME LOOP
	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;
	const int MAX_FPS = 120;

	unsigned int next_game_tick = glfwGetTime() * 1000;  //24,85 days to overflow
	int loops;
	float interpolation;

	bool game_is_running = true;

	//TESTING
	cloud1.SetSpeed(-1,-0.2,0.02);
	cloud2.SetSpeed(-0.5,0.2);

	float inputX, inputY, inputZ;
	inputX = inputY = inputZ = 0.0F;

	//ACTUAL GAME LOOP:
	while (game_is_running) {
		loops = 0;
			

		//---------------------------
		while (glfwGetTime() * 1000 > next_game_tick && loops < MAX_FRAMESKIP)
		{
			/* --- game input: --- */
			//plane.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());   //mouse picture hover

			//mouse
			if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
				lel.SetRotBy(1);
			else if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
				lel.SetRotBy(-1);
			else if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_3))
				lel.SetSpeed(0, 0, 0.01);
			else if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_3))
				lel.StopSpeed();

			//keyboard
			if (Keyboard::KeyPressed(GLFW_KEY_EQUAL))
				plane.SetScaleBy(0.01);
			else if (Keyboard::KeyPressed(GLFW_KEY_MINUS))
				plane.SetScaleBy(-0.01);
			else if (Keyboard::KeyPressed(GLFW_KEY_UP))
				plane.ChangeSpeed(0, 0.5);
			else if (Keyboard::KeyPressed(GLFW_KEY_DOWN))
				plane.ChangeSpeed(0, -0.5);
			else if (Keyboard::KeyDown(GLFW_KEY_RIGHT))
				plane.SetSpeed(5);
			else if (Keyboard::KeyDown(GLFW_KEY_LEFT))
				plane.SetSpeed(-5);

			//---------------------------

			/* --- assets logic update: --- */		
			engine.Update();

			sky.Update();
			lel.Update();
			cloud1.Update();
			cloud2.Update();
			plane.Update();
			if (next_game_tick > 3000)
				cloud1.StopSpeed("z");
			
			//---------------------------
			next_game_tick += SKIP_TICKS;
			loops++;
		}
		interpolation = float(glfwGetTime() + SKIP_TICKS - next_game_tick)
			/ float(SKIP_TICKS);
		//display_game(interpolation);
		engine.BeginRender();
		/* --- assetes render: --- */
			
		sky.Render();
		lel.Render();
		plane.Render();
		cloud1.Render();
		cloud2.Render();

		//---------------------------
		engine.EndRender();
	}
	std::cin.get();
    return 0;
}






/* =======================================================================
Usefull functions:

//mouse
plane.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());   //mouse picture hover

if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
lel.SetRotBy(1);
else if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
lel.SetRotBy(-1);
else if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_3))
lel.SetSpeed(0, 0, 0.01);
else if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_3))
lel.StopSpeed();

//keyboard
if (Keyboard::KeyPressed(GLFW_KEY_EQUAL))
plane.SetScaleBy(0.01);
if (Keyboard::KeyPressed(GLFW_KEY_MINUS))
plane.SetScaleBy(-0.01);

*/
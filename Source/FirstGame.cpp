//================== ENTRY OF PROGRAM ==================

#include "../Engine/Engine.hpp"
#include "../Graphics/Sprite.hpp"
#include "../Engine/IO/Mouse.hpp"
#include "../Engine/IO/Keyboard.hpp"
//#include "../Engine/Timer.hpp"

int main()
{
	//ENGINE AND WINDOW
	Engine engine;
	engine.initialize("Game!"); 
	
	//SPRITES INITIALIZATION:
	Sprite sky = Sprite("Assets/sky.jpg", Vector2(0, 0));
	Sprite plane = Sprite("Assets/F22.png", Vector2(0, 0));
	Sprite cloud1 = Sprite("Assets/cloud.png", Vector2(1040, 300));
	Sprite cloud2 = Sprite("Assets/cloud.png", Vector2(1040, 500));
	Sprite lel = Sprite("Assets/lel.png", Vector2(700, 200));

	//GAME LOOP
	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	unsigned int next_game_tick = glfwGetTime() * 1000;  //24,85 days to overflow
	int loops;
	//float interpolation;

	bool game_is_running = true;

	//TESTING
	lel.SetRotTo(180);
	cloud1.SetSpeedTo(Vector2(-10, 0));
	cloud2.SetSpeedTo(Vector2(-1, 0));
	cloud2.SetScaleTo(5);
	lel.SetRotSpeed(1);

	//ACTUAL GAME LOOP:
	while (game_is_running) {
		loops = 0;

		//---------------------------
		while (glfwGetTime() * 1000 > next_game_tick && loops < MAX_FRAMESKIP)
		{
			/* --- log: --- */
			cloud2.ShowInfo();

			/* --- game input: --- */
			
			//mouse
			if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
				plane.SetRotBy(1);
			else if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
				plane.SetRotBy(-1);
			else if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_3)) {
				plane.SetPos(Vector2());
				plane.StopSpeed();
				plane.SetRotTo(0);
			}
				
			//keyboard
			if (Keyboard::KeyPressed(GLFW_KEY_UP))
				plane.SetSpeedBy(Vector2(0, 0.5));
			if (Keyboard::KeyPressed(GLFW_KEY_DOWN))
				plane.SetSpeedBy(Vector2(0, -0.5));
			if (Keyboard::KeyPressed(GLFW_KEY_RIGHT))
				plane.SetSpeedBy(Vector2(0.5, 0));
			if (Keyboard::KeyPressed(GLFW_KEY_LEFT))
				plane.SetSpeedBy(Vector2(-0.5, 0));
			if (Keyboard::KeyPressed(GLFW_KEY_A))
				plane.StopSpeed("yx");

			/* --- assets logic update: --- */		
			engine.Update();

			if (cloud1.GetValue('x') < -500)
				cloud1.SetPos(Vector2(1040, 300));
			else if (cloud2.GetValue('x') < -1800)
				cloud2.SetPos(Vector2(1040, 100));

			sky.Update();
			cloud1.Update();
			lel.Update();
			cloud2.Update();

			plane.Update();

			//---------------------------
			next_game_tick += SKIP_TICKS;
			loops++;
		}
		/*
		interpolation = float(glfwGetTime() + SKIP_TICKS - next_game_tick)
			/ float(SKIP_TICKS);
		display_game(interpolation);*/
		engine.BeginRender();
		/* --- assetes render: --- */
			
		sky.Render();
		cloud2.Render();
		lel.Render();
		plane.Render();
		cloud1.Render();

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


if (Keyboard::KeyPressed(GLFW_KEY_UP))
plane.ChangeSpeed(0, 0.5);
if (Keyboard::KeyPressed(GLFW_KEY_DOWN))
plane.ChangeSpeed(0, -0.5);
if (Keyboard::KeyPressed(GLFW_KEY_RIGHT))
plane.ChangeSpeed(0.5);
if (Keyboard::KeyPressed(GLFW_KEY_LEFT))
plane.ChangeSpeed(-0.5);
if (Keyboard::KeyPressed(GLFW_KEY_A))
plane.StopSpeed("yx");

*/
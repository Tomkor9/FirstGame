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
	cloud1.SetSpeedTo(-1,-0.2,0.02);
	cloud2.SetSpeedTo(-0.5,0.2);
	lel.SetSpeedTo(0, 0, 0, 1);

	//ACTUAL GAME LOOP:
	while (game_is_running) {
		loops = 0;

		//---------------------------
		while (glfwGetTime() * 1000 > next_game_tick && loops < MAX_FRAMESKIP)
		{
			/* --- log: --- */

			/* --- game input: --- */
			//plane.SetPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());   //mouse picture hover
			
			//mouse
			if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
				plane.SetRotBy(1);
			else if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
				plane.SetRotBy(-1);
			else if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_3)) {
				plane.SetPos(0, 0);
				plane.StopSpeed();
				plane.SetRotTo(0);
			}
				
			//keyboard
			if (Keyboard::KeyPressed(GLFW_KEY_UP))
				plane.SetSpeedBy(0, 0.5);
			if (Keyboard::KeyPressed(GLFW_KEY_DOWN))
				plane.SetSpeedBy(0, -0.5);
			if (Keyboard::KeyPressed(GLFW_KEY_RIGHT))
				plane.SetSpeedBy(0.5);
			if (Keyboard::KeyPressed(GLFW_KEY_LEFT))
				plane.SetSpeedBy(-0.5);
			if (Keyboard::KeyPressed(GLFW_KEY_A))
				plane.StopSpeed("yx");

			/* --- assets logic update: --- */		
			engine.Update();

			sky.Update();
			lel.Update();
			cloud1.Update();
			cloud2.Update();
			plane.Update();

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
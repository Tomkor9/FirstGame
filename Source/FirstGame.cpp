//================== ENTRY OF PROGRAM ==================

//engine include
#include "../Engine/Engine.hpp"
#include "../Engine/Graphics/Sprite.hpp"
#include "../Engine/IO/Mouse.hpp"
#include "../Engine/IO/Keyboard.hpp"
//#include "../Engine/Timer.hpp"

//game include
#include "../Game/GamePlayer.hpp"

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

	GamePlayer player(plane);

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
	lel.SetRotSpeed(1);
	cloud1.SetSpeedTo(Vector2(-10, 0));
	cloud2.SetSpeedTo(Vector2(-1, 0));
	cloud2.SetScaleTo(5);

	//ACTUAL GAME LOOP:
	while (game_is_running) {
		loops = 0;

		//---------------------------
		while (glfwGetTime() * 1000 > next_game_tick && loops < MAX_FRAMESKIP)
		{
			/* --- log: --- */
			//cloud2.ShowInfo();

			/* --- game input: --- */
			
			//mouse
			if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
				player.GetSprite().SetRotBy(1);
			else if (Mouse::ButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
				player.GetSprite().SetRotBy(-1);
			else if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_3)) {
				player.GetSprite().SetPos(Vector2());
				player.GetSprite().StopSpeed();
				player.GetSprite().SetRotTo(0);
			}
				
			//keyboard
			if (Keyboard::KeyPressed(GLFW_KEY_UP))
				player.GetSprite().SetSpeedBy(Vector2(0, 0.5));
			if (Keyboard::KeyPressed(GLFW_KEY_DOWN))
				player.GetSprite().SetSpeedBy(Vector2(0, -0.5));
			if (Keyboard::KeyPressed(GLFW_KEY_RIGHT))
				player.GetSprite().SetSpeedBy(Vector2(0.5, 0));
			if (Keyboard::KeyPressed(GLFW_KEY_LEFT))
				player.GetSprite().SetSpeedBy(Vector2(-0.5, 0));
			if (Keyboard::KeyPressed(GLFW_KEY_A))
				player.GetSprite().StopSpeed("yx");

			/* --- assets logic update: --- */		
			engine.Update();

			if (cloud1.GetValue('x') < -500)
				cloud1.SetPos(Vector2(1040, 300));
			else if (cloud2.GetValue('x') < -2200)
				cloud2.SetPos(Vector2(1040, 100));

			sky.Update();
			cloud1.Update();
			lel.Update();
			cloud2.Update();

			player.Update();

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
		player.Render();
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
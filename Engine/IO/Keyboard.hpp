#ifndef FIRSTGAME_KEYBOARD
#define FIRSTGAME_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard{
private:
                         //true when:
static bool keys[];      //held down
static bool keysDown[];  //clicked
static bool keysUp[];    //released

public:
	static void KeyCallback(GLFWwindow* window, int key,
		int scancode, int action, int mods);

	static bool KeyDown(int key);  //int button - which button
	static bool KeyUp(int key);
	static bool KeyPressed(int key);      //current status true (up), false (down) [pressed]
};

#endif //KEYBOARD
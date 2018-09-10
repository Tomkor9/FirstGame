#ifndef FIRSTGAME_MOUSE
#define FIRSTGAME_MOUSE

#include "GLFW/glfw3.h"

class Mouse {
private:
	static double x;
	static double y;
	                            //true when:
	static bool buttons[];      //held down
	static bool buttonsDown[];  //clicked
	static bool buttonsUp[];    //released

public:
	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	
	static double getMouseX();
	static double getMouseY();

	static bool ButtonDown(int button);  //int button - which button
	static bool ButtonUp(int button);
	static bool ButtonPressed(int button);      //current status true (up), false (down) [pressed]
};

#endif //FIRSTGAME_MOUSE
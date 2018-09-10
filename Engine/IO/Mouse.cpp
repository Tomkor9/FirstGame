#include "Mouse.hpp"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { false };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { false };

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	
	x = _x;
	y = height - _y;   //relative to opened window
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0)
		return;

	//button pressed
	if (action != GLFW_RELEASE && buttons[button] == false) {
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}
	//button released
	else if (action == GLFW_RELEASE && buttons[button] == true) {
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}
	//button state update
	//if wasn't RELEASEd state is true
	//it it was RELEASEd state is false
	buttons[button] = action != GLFW_RELEASE; 
}

double Mouse::getMouseX() { return x; }
double Mouse::getMouseY() { return y; }

bool Mouse::ButtonDown(int button) {
	bool cache = buttonsDown[button];
	buttonsDown[button] = false;
	return cache;
}

bool Mouse::ButtonUp(int button) {
	bool cache = buttonsUp[button];
	buttonsUp[button] = false;
	return cache;
}

bool Mouse::ButtonPressed(int button) {
	return buttons[button];
}
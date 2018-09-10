#include "keyboard.hpp"

bool Keyboard::keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };

void Keyboard::KeyCallback(GLFWwindow* window, int key,
	int scancode, int action, int mods) {

	if (key < 0)
		return;

	//button pressed
	if (action != GLFW_RELEASE && keys[key] == false) {
		keysDown[key] = true;
		keysUp[key] = false;
	}
	//button released
	else if (action == GLFW_RELEASE && keys[key] == true) {
		keysDown[key] = false;
		keysUp[key] = true;
	}
	//button state update
	//if wasn't RELEASEd state is true
	//it it was RELEASEd state is false
	keys[key] = action != GLFW_RELEASE;
}

bool Keyboard::KeyDown(int key) {
	bool cache = keysDown[key];
	keysDown[key] = false;
	return cache;
}

bool Keyboard::KeyUp(int key) {
	bool cache = keysUp[key];
	keysUp[key] = false;
	return cache;
}

bool Keyboard::KeyPressed(int key) {
	return keys[key];
}
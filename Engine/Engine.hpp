#ifndef FIRSTGAME_ENGINE
#define FIRSTGAME_ENGINE

#include "GLFW/glfw3.h"                //adding opengl
#pragma comment(lib, "opengl32.lib")   //or: "-lopengl32.lib" in cmake

class Engine{
private:
	static GLFWwindow* window;
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	bool initialize(char* windowTitle);  //creates window

	void Update();
	void BeginRender();
	void EndRender();

	Engine();
	~Engine();
};

#endif //FIRSTGAME_ENGINE


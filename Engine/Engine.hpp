#ifndef FIRSTGAME_ENGINE
#define FIRSTGAME_ENGINE

#include "ELog.hpp"
#include "GLFW/glfw3.h"                //adding opengl
#pragma comment(lib, "opengl32.lib")   //or: "-lopengl32.lib" in cmake

class Engine : public Elog{
private:
	static GLFWwindow* window;
	static double dt;                  //delta time
	double pt;                         //previous time (time it gets to make a game loop)
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static double GetDT();

	bool initialize(char* windowTitle);  //creates window

	void Update();
	void BeginRender();
	void EndRender();

	Engine();
	~Engine();
};

#endif //FIRSTGAME_ENGINE


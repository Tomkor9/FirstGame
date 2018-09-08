#ifndef FIRSTGAME_ENGINE
#define FIRSTGAME_ENGINE

#include "ELog.hpp"
#include "GLFW\glfw3.h"                //adding opengl
#pragma comment(lib, "opengl32.lib")   //or: "-lopengl32.lib" in cmake

class Engine : public Elog{
private:
	static GLFWwindow* window;
	unsigned long time_start_ms;
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	
	unsigned long get_current_time();     //returns time in ms elapsed since engine start

	bool initialize(char* windowTitle);  //creates window
	void Update();
	void BeginRender();
	void EndRender();

	Engine();
	~Engine();
};

#endif //FIRSTGAME_ENGINE


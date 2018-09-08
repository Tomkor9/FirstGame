#include "Engine.hpp"
#include <chrono>
#include <iostream>

//STATIC members initialization
int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = nullptr;

//max value of unsigned long = 4 294 967 395 (0xffffffff)
unsigned long Engine::get_current_time() {
	return (std::chrono::duration<double>
		(std::chrono::steady_clock::now().time_since_epoch()).count() * 1000) - time_start_ms;
}

Engine::Engine(){
	time_start_ms = std::chrono::duration<double>
		(std::chrono::steady_clock::now().time_since_epoch()).count() * 1000;
}

Engine::~Engine() {

}

bool Engine::initialize(char* windowTitle) {
	if (!glfwInit()) {
		logInfo("Error initializing GLFW!", 1);
		return false;
	}
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
		windowTitle, nullptr, nullptr);

	if (window == nullptr) {
		logInfo("Error creating window!", 1);
		return false;
	}

	/* GLFW Setup */
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1); //render one frame ahead to swap (eliminates flickering)

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor()); //gets display res
	int xPos = (mode->width - SCREEN_WIDTH) / 2;   //center position x of monitor
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;   //center position y of monitor
	glfwSetWindowPos(window, xPos, yPos);

	/* GL Setup */
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION); //2D matrix projection
	glLoadIdentity(); //refresh all the marices (identity matrix is one we start with)
	glOrtho(0, width, 0, height, -10, 10); //setting camera position and depth
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW); //allows loading 2D assets (it's like a switch state for next functions)

	//Alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	logInfo("Initialization successful", 0);
	return true;
}

void Engine::BeginRender() {
	glClearColor(1, 1, 0, 1); //clearing back buffer (CAN CHANGE!)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clearing depth buffer
}

void Engine::EndRender() {
	glfwSwapBuffers(window);
}

//processing queued events like mouse drag etc.
void Engine::Update() {
	glfwPollEvents(); 
}
#include "Engine.hpp"
#include "IO\Mouse.hpp"
#include "IO\Keyboard.hpp"
#include <iostream>

//STATIC members initialization
int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = nullptr;

Engine::Engine(){}

Engine::~Engine() {}

bool Engine::initialize(char* windowTitle) {
	if (!glfwInit()) {
		std::cout<<"Error initializing GLFW!\n";
		return false;
	}
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
		windowTitle, nullptr, nullptr);

	if (window == nullptr) {
		std::cout << "Error creating a window!\n";
		return false;
	}

	/* GLFW Setup */
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1); //render one frame ahead to swap (eliminates flickering)

	//Input handling
	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor()); //gets display res
	int xPos = (mode->width - SCREEN_WIDTH) / 2;     //center position x of monitor
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;   //center position y of monitor
	glfwSetWindowPos(window, xPos, yPos);

	/* GL Setup */
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);              //2D matrix projection
	glLoadIdentity();                         //refresh all the marices (identity matrix is one we start with)
	glOrtho(0, width, 0, height, -10, 10);    //setting camera position and depth
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);               //allows loading 2D assets (it's like a switch state for next functions)

	//Alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);  //fixed alpha effects handling
												  //old with black artefacts: glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Engine timer
	glfwSetTime(0.0);                             //sets game engine timer to 0                           

	std::cout << "Initialization successful!\n";
	return true;
}

void Engine::Update() {                           //processing queued events like mouse drag etc.
	glfwPollEvents();
}

void Engine::BeginRender() {
	glClearColor(0, 0, 0, 1);                      //clearing back buffer (color can be changed)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                 //clearing depth buffer
}

void Engine::EndRender() {
	glfwSwapBuffers(window);
}
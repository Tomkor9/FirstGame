#ifndef FIRSTGAME_SPRITE
#define FIRSTGAME_SPRITE

#include "GLFW\glfw3.h"
#include "Texture.hpp"

#include <iostream>
#include <string>

class Sprite {
private:
	Texture texture;
	float xPos;
	float yPos;

public:
	Sprite();
	Sprite(std::string imagePath);
	Sprite(std::string imagePath, float _xPos, float _yPos);

	void Update();
	void Render();

	void SetPos(float x, float y);
};

#endif //FIRSTGAME_SPRITE
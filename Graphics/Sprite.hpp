#ifndef FIRSTGAME_SPRITE
#define FIRSTGAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.hpp"

#include <iostream>
#include <string>

class Sprite {
private:
	Texture texture;
	float xPos;
	float yPos;
	float rot;
	float xScale;
	float yScale;

public:
	Sprite();
	Sprite(std::string imagePath);
	Sprite(std::string imagePath, float _xPos, float _yPos, float _rot = 0, float _xScale = 1, float _yScale = 1);

	void Update();
	void Render();

	void SetPos(float x, float y);
	void SetRotTo(float rotation);   //rotate by degrees ABS (setting rotation value)
	void SetRotBy(float rotation);   //rotate by degrees relatively (adding rotation value)
	void SetScale(float xy);         //symetric scale
	void SetScale(float x, float y); //asymetric scale
};

#endif //FIRSTGAME_SPRITE
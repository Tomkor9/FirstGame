#ifndef FIRSTGAME_SPRITE
#define FIRSTGAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.hpp"

class Sprite {
private:
	Texture texture;
	float xPos;
	float yPos;
	float rot;
	float xScale;
	float yScale;

	float xSpeed;
	float ySpeed;
	float zSpeed;

public:
	bool inMotion;
	Sprite();
	~Sprite();
	Sprite(std::string imagePath);
	Sprite(std::string imagePath, float _xPos, float _yPos, float _rot = 0, float _xScale = 1, float _yScale = 1);

	void Update();
	void Render();

	void SetPos(float x, float y);
	void SetRotTo(float rotation);   //rotate by degrees ABS (setting rotation value)
	void SetRotBy(float rotation);   //rotate by degrees relatively (adding rotation value)
	void SetScaleTo(float xy);         //symetric scale
	void SetScaleTo(float x, float y); //asymetric scale
	void SetScaleBy(float xy);         
	void SetScaleBy(float x, float y); 
	
	void SetSpeed(float x = 0, float y = 0, float z = 0); // pixels per frame (can be fraction)
	void ChangeSpeed(float x = 0, float y = 0, float z = 0);
	void StopSpeed(std::string flags = "xyz");
	void UpdateMotionStatus();
};

#endif //FIRSTGAME_SPRITE
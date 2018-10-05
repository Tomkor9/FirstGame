#ifndef FIRSTGAME_SPRITE
#define FIRSTGAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.hpp"
#include "../Engine/Calculations/Vector2.hpp"

class Sprite {
private:
	Texture texture;
	
	Vector2 pos;
	Vector2 scale;
	float rot;

	bool inMotion = false;
	Vector2 speed;
	float rotSpeed;

public:
	Sprite();
	~Sprite();
	Sprite(std::string imagePath);
	Sprite(std::string imagePath, Vector2 _pos);

	void Update();
	void Render();

	void SetPos(Vector2 _pos);
	
	void SetRotTo(float rotation);     //rotate by degrees ABS (setting rotation value)
	void SetRotBy(float rotation);     //rotate by degrees relatively (adding rotation value)
	void SetRotSpeed(float rottion);
	
	void SetScaleTo(float xy);         //symetric scale
	void SetScaleTo(Vector2 v);        //asymetric scale
	void SetScaleBy(float xy);         
	void SetScaleBy(Vector2 v);
	
	void SetSpeedTo(Vector2 _vec);     // pixels per game speed (can be fraction)
	void SetSpeedBy(Vector2 _vec);
	void StopSpeed(std::string flags = "xyzr");
	
	float GetValue(char flag);        //position: x,y,r; scale: a,b (a = scale x, b = scale y)
	float GetSpeed(char flag);        //x, y, r (rotation)
	void UpdateMotionStatus();

	void ShowInfo();                  // !! should be another class defining interface deriving from this
};

#endif //FIRSTGAME_SPRITE
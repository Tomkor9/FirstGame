#ifndef FIRSTGAME_SPRITE
#define FIRSTGAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.hpp"
#include "../../Engine/Calculations/Vector2.hpp"

class Sprite {
protected:
	Texture texture;

	Vector2 pos;
	Vector2 size;
	Vector2 speed;
	Vector2 scale;

	float rot;
	float rotSpeed;

	bool inMotion = false;
	
public:
	Sprite();
	~Sprite();
	Sprite(std::string imagePath);
	Sprite(std::string imagePath, Vector2 _pos);

	void UpdateSprite();
	void RenderSprite();

	void SetPos(Vector2 _pos);
	
	void SetRotTo(float rotation);     //rotate by degrees ABS (setting rotation value)
	void SetRotBy(float rotation);     //rotate by degrees relatively (adding rotation value)
	void SetRotSpeed(float rottion);
	
	void SetScaleTo(float xy);         //symetric scale
	void SetScaleTo(Vector2 v);        //asymetric scale
	void SetScaleBy(float xy);
	void SetScaleBy(Vector2 v);
	void SetSizeTo(Vector2 _size);
	
	void SetSpeedTo(Vector2 _vec);     //pixels per game speed (can be fraction)
	void SetSpeedBy(Vector2 _vec);

	void StopSpeed(std::string flags = "xyzr");
	
	float GetValue(char flag) const;         //position: x,y,r; scale: a,b (a = scale x, b = scale y)
	float GetAxisSpeed(char flag) const;         //x, y, r (rotation)
	Texture GetTexture() const;


	void UpdateMotionStatus();

	void ShowInfo();                   // !! should be another class defining interface deriving from this
};

#endif //FIRSTGAME_SPRITE
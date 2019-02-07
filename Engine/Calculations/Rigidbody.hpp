#ifndef FIRSTGAME_RIGIDBODY
#define FIRSTGAME_RIGIDBODY
#include "Vector2.hpp"
#include "../Graphics/Sprite.hpp"

class Rigidbody : public Sprite {
private:
	Vector2 pos;
	Vector2 scale;
	Vector2 size;      //pass texture width and height
	Vector2 velocity;
	float rot;

	float gravity;
	float friction;

	bool borders;
public:
	Rigidbody();
	void Initialize(float _gravity, float _friction, Vector2 _pos, float _rot, Vector2 _scale, Vector2 _size, Vector2 _speed);

	void SetGravity(float grav);
	void SetFriction(float frict);

	void UpdateRB(); 
	void RenderRB(float R = 1.0F, float G = 0.0F, float B = 0.0F);

	void AddForce(Vector2 force);
	void DrawBorders(bool state);
};


#endif //FIRSTGAME_RIGIDBODY

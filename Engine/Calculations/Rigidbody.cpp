#include "Rigidbody.hpp"
#include "../Engine.hpp"

Rigidbody::Rigidbody() {
	friction = 1.0F;  // 0.9 - add speed, 1 - no friction, 1.1 - more friction
	gravity = 0.0F;   // -0.1 - revert gravity, 0 - no gravity, 0.1 - normal grav
	borders = false;
}

void Rigidbody::Initialize(float _gravity, float _friction, Vector2 _pos,
	float _rot, Vector2 _scale, Vector2 _size, Vector2 _speed){

	friction = _friction;
	gravity = _gravity;
	
	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
	velocity = _speed;
}

void Rigidbody::UpdateRB(){
	velocity.x /= friction;
	velocity.y -= gravity;

	pos += velocity;
}

void Rigidbody::RenderRB(float R, float G, float B){
	glLoadIdentity();
	
	glTranslatef(pos.x, pos.y, 0.0F);
	glRotatef(rot, 0.0F, 0.0F, 1.0F);
	glScalef(scale.x, scale.y, 0.0F);

	glColor4f(R, G, B, 1); //(R, G, B, alpha)

	if (borders){
		glBegin(GL_LINES);
		{
			//line projection in groupings of two
			glVertex2f(0, 0);
			glVertex2f(size.x, 0);

			glVertex2f(size.x, 0);
			glVertex2f(size.x, size.y);

			glVertex2f(size.x, size.y);
			glVertex2f(0, size.y);

			glVertex2f(0, size.y);
			glVertex2f(0, 0);
		}}
	glEnd();
}

void Rigidbody::AddForce(Vector2 force) {
	velocity += force;
}

void Rigidbody::DrawBorders(bool state)
{
	borders = state;
}

void Rigidbody::SetFriction(float fric)
{
	friction = fric;
}

void Rigidbody::SetGravity(float grav)
{
	friction = grav;
}
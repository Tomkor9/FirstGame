#include "Rigitbody.hpp"
#include "../Engine.hpp"

Rigidbody::Rigidbody() {
	friction = 1;
	gravity = 0;
}

void Rigidbody::Initialize(float _gravity, float _friction, Vector2 * _pos, float * _rot, Vector2 * _scale, Vector2* _size){
	friction = _friction;
	gravity = _gravity;
	
	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
}

void Rigidbody::Update(){
	velocity.x *= friction;
	velocity.y -= gravity;

	*pos += velocity;
}

void Rigidbody::Render(float R, float G, float B){
	glLoadIdentity();
	
	glTranslatef(pos->x, pos->y, 0.0F);
	glRotatef(*rot, 0.0F, 0.0F, 1.0F);
	glScalef(scale->x, scale->y, 0.0F);

	glColor4f(R, G, B, 1); //(R, G, B, alpha)
	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i(size->x, 0);
		glVertex2i(size->x, size->y);
		glVertex2i(0, size->y);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector2 force) {
	velocity += force;
}
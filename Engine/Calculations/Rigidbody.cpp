#include "Rigidbody.hpp"
#include "../Engine.hpp"

Rigidbody::Rigidbody() {
	friction = 1;  //(float) 1 - no friction, 0 - full friction
	gravity = 0;
	borders = false;
}

void Rigidbody::Initialize(float _gravity, float _friction, Vector2 *_pos,
	float *_rot, Vector2 *_scale, Vector2 *_size){

	friction = _friction;
	gravity = _gravity;
	
	pos = _pos;
	rot = _rot;
	scale = _scale;
	size = _size;
	//add velocity!
}

//nie dziala
void Rigidbody::Update(){
	velocity.x *= friction;
	velocity.y -= gravity;

	printf("friction %d, velocity.x %d\n", friction, velocity.x);
	printf("gravity %d, velocity.y %d\n", gravity, velocity.y);

	*pos += velocity;
}

void Rigidbody::Render(float R, float G, float B){
	glLoadIdentity();
	
	glTranslatef(pos->x, pos->y, 0.0F);
	glRotatef(*rot, 0.0F, 0.0F, 1.0F);
	glScalef(scale->x, scale->y, 0.0F);

	glColor4f(R, G, B, 1); //(R, G, B, alpha)

	if (borders){
		glBegin(GL_LINES);
		{
			//line projection in groupings of two
			glVertex2f(0, 0);
			glVertex2f(size->x, 0);

			glVertex2f(size->x, 0);
			glVertex2f(size->x, size->y);

			glVertex2f(size->x, size->y);
			glVertex2f(0, size->y);

			glVertex2f(0, size->y);
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

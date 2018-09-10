#include "Sprite.hpp"

Sprite::Sprite(){
	xPos = 0; yPos = 0; rot = 0; xScale = 1; yScale = 1;
	texture = Texture();   //redundant empty constructor
}

Sprite::Sprite(std::string imagePath) {
	xPos = 0; yPos = 0;; rot = 0; xScale = 1; yScale = 1;
	texture = Texture(imagePath);
}

Sprite::Sprite(std::string imagePath, float _xPos, float _yPos,
	float _rot, float _xScale, float _yScale) {

	xPos = _xPos;
	yPos = _yPos;
	rot = _rot;
	if (_yScale != 1) {
		xScale = _xScale;
		yScale = _xScale;
	}
	else {
		xScale = _xScale;
		yScale = _yScale;
	}	
	texture = Texture(imagePath);
}

void Sprite::Update() {
	
}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();        //starting from empty identity matrix

	//TRANSLATE, ROTATE, SCALE
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);
	

	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0);    glVertex2i(0, 0);
	glTexCoord2i(1, 0);    glVertex2i(texture.getWidth(), 0);
	glTexCoord2i(1, 1);    glVertex2i(texture.getWidth(), texture.getHeight());
	glTexCoord2i(0, 1);    glVertex2i(0, texture.getHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SetPos(float x, float y){
	xPos = x;
	yPos = y;
}

void Sprite::SetRotTo(float rotation) {
	rot = rotation;
}

void Sprite::SetRotBy(float rotation) {
	rot += rotation;
}

void Sprite::SetScale(float xy) {
	xScale = xy;
	yScale = xy;
}

void Sprite::SetScale(float x, float y) {
	xScale = x; yScale = y;
}
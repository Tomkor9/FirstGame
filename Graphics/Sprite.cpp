#include "Sprite.hpp"

Sprite::Sprite(){
	xPos = 0; yPos = 0;
	texture = Texture();   //redundant empty constructor
}

Sprite::Sprite(std::string imagePath) {
	xPos = 0; yPos = 0;
	texture = Texture(imagePath);
}

Sprite::Sprite(std::string imagePath, float _xPos, float _yPos) {
	xPos = _xPos; yPos = _yPos;
	texture = Texture(imagePath);
}

void Sprite::Update() {

}

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();        //starting from empty identity matrix

	//TRANSLATE -> ROTATE -> SCALE
	glTranslatef(xPos, yPos, 0);

	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);    glVertex2f(0, 0);
	glTexCoord2f(1, 0);    glVertex2f(texture.getWidth(), 0);
	glTexCoord2f(1, 1);    glVertex2f(texture.getWidth(), texture.getHeight());
	glTexCoord2f(0, 1);    glVertex2f(0, texture.getHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
#include "Sprite.hpp"

//====CONSTRUCTORS

Sprite::Sprite(){
	xPos = 0; yPos = 0; rot = 0; xScale = 1; yScale = 1;
	xSpeed = 0; ySpeed = 0; zSpeed = 0; inMotion = false;
	texture = Texture();   //redundant empty constructor
}

Sprite::Sprite(std::string imagePath) {
	xPos = 0; yPos = 0;; rot = 0; xScale = 1; yScale = 1;
	xSpeed = 0; ySpeed = 0; zSpeed = 0; inMotion = false;
	texture = Texture(imagePath);
}

Sprite::Sprite(std::string imagePath, float _xPos, float _yPos,
	float _rot, float _xScale, float _yScale) {
	
	xSpeed = 0; ySpeed = 0; zSpeed = 0; inMotion = false;
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

Sprite::~Sprite() {
	std::cout << "Destroyed sprite (texture id:" << texture.getID() << ")\n";
}

//====UPDATE LOGIC

void Sprite::Update() {
	if (inMotion == true) {
		xPos += xSpeed;
		yPos += ySpeed;
		xScale += zSpeed;
		yScale += zSpeed;
}}

//====RENDER LOGIC

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

//====METHODS

//MANIPULATION
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

void Sprite::SetScaleTo(float xy) {
	xScale = xy;
	yScale = xy;
}

void Sprite::SetScaleTo(float x, float y) {
	xScale = x; yScale = y;
}

void Sprite::SetScaleBy(float xy) {
	xScale += xy;
	yScale += xy;
}

void Sprite::SetScaleBy(float x, float y) {
	xScale += x; yScale += y;
}

//MOVEMENT
void Sprite::SetSpeed(float x, float y, float z) {
	xSpeed = x;
	ySpeed = y;
	zSpeed = z;
	UpdateMotionStatus();
}

void Sprite::ChangeSpeed(float x, float y, float z) {
	xSpeed += x;
	ySpeed += y;
	zSpeed += z;
	UpdateMotionStatus();
}

/* "xyz" - stop in all directions (default)
   "xz", "xy", ... - stop in multible axes
   "x", "y", "z" - stop in given axis  */
void Sprite::StopSpeed(std::string flags) {
	for (char c = 0; c < flags.size(); c++) {
		switch (flags.at(c)) {
		case 'x': xSpeed = 0; break;
		case 'y': ySpeed = 0; break;
		case 'z': zSpeed = 0; break;
		default: break;
		}
		UpdateMotionStatus();
}}

void Sprite::UpdateMotionStatus() {
	if (xSpeed == 0 && ySpeed == 0 && zSpeed == 0)
		inMotion = false;
	else
		inMotion = true;
}

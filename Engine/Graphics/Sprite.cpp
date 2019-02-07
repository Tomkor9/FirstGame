#include "Sprite.hpp"
#include "../../Engine/Engine.hpp"
                                
#include <iomanip>

//====CONSTRUCTORS

Sprite::Sprite(){

	texture = Texture();
	pos = Vector2();
	scale = Vector2(1,1);
	speed = Vector2(0,0);
	size = Vector2(texture.getWidth(), texture.getHeight());
	rotSpeed = 0;

	rot = 0;
}

Sprite::Sprite(std::string imagePath) {
	texture = Texture(imagePath);
	pos = Vector2();
	scale = Vector2(1, 1);
	speed = Vector2(0, 0);
	size = Vector2(texture.getWidth(), texture.getHeight());
	rotSpeed = 0;
	
	rot = 0;
}

Sprite::Sprite(std::string imagePath, Vector2 _pos){
	
	texture = Texture(imagePath);
	pos = _pos;
	rot = 0;

	speed = Vector2(0, 0);
	rotSpeed = 0;

	//make elog
	//printf("- created Sprite tex(%d) %s %d, %d\n",
		//texture.getID(), texture.getName().c_str(), texture.getHeight(), texture.getWidth());

	size = Vector2(texture.getWidth(), texture.getHeight());
	scale = Vector2(1, 1);
}

Sprite::~Sprite() {
	//ELOG
	std::cout << "Sprite(" << texture.getID() << "): "
		      << texture.getName() << " - Destroyed\n";
}

//====RENDER LOGIC

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();        //starting from empty identity matrix

	//TRANSLATE, ROTATE, SCALE
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);
	

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
void Sprite::SetPos(Vector2 _pos){
	pos = _pos;
}

void Sprite::SetRotTo(float rotation) {
	rot = rotation;
}

void Sprite::SetRotBy(float rotation) {
	rot += rotation;
}

void Sprite::SetScaleTo(float xy) {
	scale.x = xy;
	scale.y = xy;
}

void Sprite::SetScaleTo(Vector2 v) {
	scale = v;
}

void Sprite::SetScaleBy(float xy) {
	scale.x += xy;
	scale.y += xy;
}

void Sprite::SetScaleBy(Vector2 v) {
	scale += v;
}
//RETURNIGN INFO

//position: x,y,r; scale: a,b (a = scale x, b = scale y)
float Sprite::GetValue(char flag) const {
	switch (flag)
	{
	case 'x': return pos.x; break;
	case 'y': return pos.y; break;
	case 'a': return scale.x; break;
	case 'b': return scale.y; break;
	case 'r': return rot; break;
	default: return 0.0F;
	}
}

//x, y, r (rotation)
float Sprite::GetAxisSpeed(char flag) const {
	switch (flag)
	{
	case 'x': return speed.x; break;
	case 'y': return speed.y; break;
	case 'r': return rotSpeed; break;
	default: return 0.0F;
	}
}

// change it (public-private variables)
Vector2 * Sprite::GetPos()
{
	return &pos;
}

float * Sprite::GetRot()
{
	return &rot;
}

Vector2 * Sprite::GetScale()
{
	return &scale;
}

Vector2 * Sprite::GetSize()
{
	return &size;
}

Vector2 * Sprite::GetSpeed()
{
	return &speed;
}

//---------------------------------------

void Sprite::ShowInfo() {
	std::cout << std::setprecision(5) <<
		texture.getName() << " ID " << texture.getID() << ":\n"
		"POS x " << pos.x << " y " << pos.y << "\n" <<
		"SCL x " << scale.x << " y " << scale.y << "\n" <<
		"SPD" << inMotion << " x " << speed.x << " y " << speed.y << " r " << rotSpeed << "\n";
}

//MOVEMENT

void Sprite::SetRotSpeed(float rotation) {
	rotSpeed = rotation;
	UpdateMotionStatus();
}

void Sprite::SetSpeedTo(Vector2 _vec) {
	speed = _vec;
	UpdateMotionStatus();
}

void Sprite::SetSpeedBy(Vector2 _vec) {
	speed += _vec;
	UpdateMotionStatus();
}

/* "xyr" - stop in all directions + rotation (default)
   "xz", "xy", ... - stop in multible axes
   "x", "y", "r" - stop in given axis  */
void Sprite::StopSpeed(std::string flags) {
	for (unsigned char c = 0; c < flags.size(); c++) {
		switch (flags.at(c)) {
		case 'x': speed.x = 0; break;
		case 'y': speed.y = 0; break;
		case 'r': rotSpeed = 0; break;
		default: break;
		}
		UpdateMotionStatus();
}}

void Sprite::UpdateMotionStatus() {
	inMotion = !(speed.x == 0 && speed.y == 0 && rotSpeed == 0);
}

//====UPDATE LOGIC

void Sprite::Update() {
	if (inMotion == true) {
		pos += speed;
		rot += rotSpeed;
	}
}
#ifndef FIRSTGAME_TEXTURE
#define FIRSTGAME_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"

#include <iostream>
#include <string>

class Texture
{
private:
	int id;
	int width;
	int height;
	
	bool GetTextureParams();
public:
	Texture();
	Texture(int _id);
	Texture(std::string path);

	int getID();
	int getWidth();
	int getHeight();
};

#endif //FIRSTGAME_TEXTURE
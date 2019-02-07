#ifndef FIRSTGAME_TEXTURE
#define FIRSTGAME_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"

#include <string>
#include <iostream>

class Texture
{
private:
	int id;
	int width;
	int height;
	std::string name;
	
	bool GetTextureParams();
public:
	Texture();
	~Texture();
	Texture(int _id, std::string _name = "");
	Texture(std::string path);

	int getID();
	int getWidth();
	int getHeight();
	std::string getName();
};

#endif //FIRSTGAME_TEXTURE
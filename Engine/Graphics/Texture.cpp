#include "Texture.hpp"

Texture::Texture() { id = -1; }

Texture::Texture(int _id, std::string _name) {

	if (!GetTextureParams())
		std::cout << "Error loading image: " << id << "\n";  //INSERT ELOG HERE
	id = _id; 
	
	//generating name
	if (_name != "")
		name = _name;
	else
		name = "texture";
}

Texture::Texture(std::string path) {
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!GetTextureParams()) 
		std::cout << "Error loading image: " << path << "\n";  //INSERT ELOG HERE

	//generating name
	for (int i = path.size()-1 ; i >= 0; i--) {
		if (path.at(i) == '\\' || path.at(i) == '/')
			break;
		name += path.at(i);
	}
	std::reverse(name.begin(), name.end());
}

Texture::~Texture() {

}

bool Texture::GetTextureParams(){

	if (id > 0)
	{
		int mipLevel = 0; //impage compression (mipmap)
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);   //store loaded image width in &width
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height); //store loaded image width in &height
		return true;    //INSERT ELOG HERE
	}
	return false;     //INSERT ELOG HERE
}

int Texture::getID() { return id; }
std::string Texture::getName() { return name; }
int Texture::getHeight() { return height; }
int Texture::getWidth() { return width; }
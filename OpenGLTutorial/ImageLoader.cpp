#include "ImageLoader.h"
#include "picoPNG.h"
#include "IOManager.h"
#include "Errors.h"

#include <vector>

GLTexture ImageLoader::loadPNG(const std::string & filePath) {
	
	GLTexture texture = {};

	std::vector<unsigned char> in;
	std::vector<unsigned char> out;
	unsigned long width, height;

	if (IOManager::readFileToBuffer(filePath, in) ==  false) {
		fatalError("Failed to load png file into buffer");
	}
	int errorCode = decodePNG(out, width, height, &in[0], in.size());

	if (errorCode != 0) {
		fatalError("decodePNG failed with error: " + errorCode);
	}

	//Create openGL texture
	//Generate object
	glGenTextures(1, &(texture.id));

	//bind texture
	glBindTexture(GL_TEXTURE_2D, texture.id);

	//Upload image data to texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

	//Give openGL parameter infomation
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	//Mipmapping
	glGenerateMipmap(GL_TEXTURE_2D);

	//Unbind textures
	glBindTexture(GL_TEXTURE_2D, 0);

	texture.width = width;
	texture.height = height;
	return texture;
}

#include "ImageLoader.h"
#include "picoPNG.h"

#include <vector>

ImageLoader::ImageLoader() {
}


ImageLoader::~ImageLoader() {
}

GLTexture ImageLoader::loadPNG(const std::string & filepath) {
	
	GLTexture texture = {};


	std::vector<unsigned char> out;
	unsigned long width, height;
	int errorCode = decodePNG(out, width, height, )

	return texture;
}

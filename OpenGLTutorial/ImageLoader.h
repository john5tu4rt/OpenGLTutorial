#pragma once

#include <string>

#include "GLTexture.h"

class ImageLoader {
public:
	ImageLoader();
	~ImageLoader();

	GLTexture loadPNG(const std::string& filepath);
};


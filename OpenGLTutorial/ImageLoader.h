#pragma once

#include <string>

#include "GLTexture.h"

class ImageLoader {
public:

	GLTexture loadPNG(const std::string& filePath);
};


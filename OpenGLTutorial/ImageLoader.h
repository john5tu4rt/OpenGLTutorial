#pragma once

#include <string>

#include "GLTexture.h"

class ImageLoader {
public:
	static GLTexture loadPNG(const std::string& filePath);
};


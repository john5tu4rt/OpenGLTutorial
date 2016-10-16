#pragma once

#include <GL\glew.h>

//multiple of 4 bytes for efficiency (float is 4 bytes, so 8 here)

struct Vertex {
	struct Position {
		float x, y;
	} position;	
	
	struct Color {
		GLubyte r, g, b, a;
	} color;
};

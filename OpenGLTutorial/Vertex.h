#pragma once

#include <GL\glew.h>

//multiple of 4 bytes for efficiency (float is 4 bytes, so 8 here)

struct Position {
	float x, y;
};

struct Color {
	GLubyte r, g, b, a;
};

struct Vertex {
	 Position position;	
	 Color color;
};

#pragma once

#include <GL\glew.h>

//multiple of 4 bytes for efficiency (float is 4 bytes, so 8 here)

struct Position {
	float x, y;
};

struct Color {
	GLubyte r, g, b, a;
};

struct UV {
	float u, v;
};

struct Vertex {
	/*
		Storing a struct or class inside another struct or class
		inside another struct or class is called compostion.
		This is layed out in memory exactly the same as if
		we had a position[2]. This construction is useful mentally.
	*/
	 Position position;

	 //rgba color - 4 bytes
	 Color color;

	 //UV texture coords
	 UV uv;
	 
	 void setPosition(float x, float y) {
		 position.x = x;
		 position.y = y;
	 }

	 void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
		 color.r = r;
		 color.g = g;
		 color.b = b;
		 color.a = a;
	 }

	 void setUV(float u, float v) {
		 uv.u = u;
		 uv.v = v;
	 }
};

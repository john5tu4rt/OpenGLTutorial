#pragma once
#include <GL/glew.h>


class Sprite {
public:
	Sprite();
	~Sprite();

	void init(int x, int y, int width, int height); // should this be in the constructor

	void draw();

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	GLuint m_vboID; // GLuint is guaranteed to be 32 bits unsigned
};


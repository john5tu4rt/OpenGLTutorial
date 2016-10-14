#pragma once
#include <GL/glew.h>


class Sprite {
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height); // should this be in the constructor

	void draw();

private:
	float m_x;
	float m_y;
	float m_width;
	float m_height;
	GLuint m_vboID; // GLuint is guaranteed to be 32 bits unsigned
};


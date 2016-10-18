#include "Sprite.h"
#include "Vertex.h"

#include <cstddef>


Sprite::Sprite() {
	m_vboID = 0;
}


Sprite::~Sprite() {
	if (m_vboID != 0) {
		glDeleteBuffers(1,&m_vboID);
	}
}
void Sprite::init(float x, float y, float width, float height) {
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;

	if (m_vboID == 0) {
		glGenBuffers(1, &m_vboID);
	}

	Vertex vertexData[6]; // 6 vertices with 2 co ords each

	vertexData[0].setPosition(x + width, y + height);
	vertexData[0].setUV(1.f, 1.f);
	vertexData[1].setPosition(x, y + height);
	vertexData[1].setUV(0.f, 1.f);
	vertexData[2].setPosition(x, y);
	vertexData[2].setUV(0.f, 0.f);
	vertexData[3].setPosition(x, y);
	vertexData[3].setUV(0.f, 0.f);
	vertexData[4].setPosition(x + width, y);
	vertexData[4].setUV(1.f, 0.f);
	vertexData[5].setPosition(x + width, y + height);
	vertexData[5].setUV(1.f, 1.f);

	for (auto &i : vertexData) {
		i.setColor(40, 40, 40, 255);
	}
	
	//Tell openGL to bind our vertex buffer object
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	//Upload the data to the GPU
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);


	//Unbind the buffer (optional)
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::draw() {

	//bind the buffer object
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

	//Tell openGL that we want to use the first attribute array,
	//We only need one since we are only using posititon
	glEnableVertexAttribArray(0);

	//This is the position attribute pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	//This is the color attribute pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	//This is the UV attribute pointer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	//Draw the 6 vertices to screen
	glDrawArrays(GL_TRIANGLES, 0, 6);


	//Disable the vertex attrib array - Necessary
	glDisableVertexAttribArray(0);

	//Unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

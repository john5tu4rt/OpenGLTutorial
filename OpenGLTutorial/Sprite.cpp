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

	vertexData[0].position.x = x + width;
	vertexData[0].position.y = y + height;

	vertexData[1].position.x = x;
	vertexData[1].position.y = y + height;
	
	vertexData[2].position.x = x;
	vertexData[2].position.y = y;
	
	vertexData[3].position.x = x;
	vertexData[3].position.y = y;
	
	vertexData[4].position.x = x + width;
	vertexData[4].position.y = y;
	
	vertexData[5].position.x = x + width;
	vertexData[5].position.y = y + height;

	for (auto &i : vertexData) {
		i.color.r = 255;
		i.color.g = 0;
		i.color.b = 255;
		i.color.a = 255;
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

	//Draw the 6 vertices to screen
	glDrawArrays(GL_TRIANGLES, 0, 6);


	//Disable the vertex attrib array - Necessary
	glDisableVertexAttribArray(0);

	//Unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

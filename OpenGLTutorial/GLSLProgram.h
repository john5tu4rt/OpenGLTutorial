#pragma once

#include <string>
#include <GL/glew.h>

//GLSL is the open GL programming language used through the 2 text files
//shader.vert, shader.frag

class GLSLProgram {
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShaders();

private:

	void compileShader(const std::string& filePath, const GLuint& shaderID);

	GLuint m_programID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
};


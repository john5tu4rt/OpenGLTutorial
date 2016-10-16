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

	void addAttribute(const std::string& attributeName);

	GLuint getUniformLocation(const std::string& uniformName);

	void use();
	void unuse();

private:
	int m_numAttributes;
	void compileShader(const std::string& filePath, const GLuint& shaderID);

	GLuint m_programID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
};


#include "GLSLProgram.h"
#include "Errors.h"
#include <fstream>
#include <vector>

using namespace std::string_literals;

GLSLProgram::GLSLProgram() : m_programID(0),
							m_vertexShaderID(0),
							m_fragmentShaderID(0) {
}


GLSLProgram::~GLSLProgram() {
}

void GLSLProgram::compileShaders(const std::string & vertexShaderFilePath, const std::string & fragmentShaderFilePath) {

	m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (m_vertexShaderID == 0) {
		fatalError("Vertex shader failed to be created");
	}

	m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (m_fragmentShaderID == 0) {
		fatalError("Fragment shader failed to be created");
	}

	compileShader(vertexShaderFilePath, m_vertexShaderID);
	compileShader(fragmentShaderFilePath, m_fragmentShaderID);
}

void GLSLProgram::linkShaders() {

	//Create a program object
	m_programID = glCreateProgram();

	glAttachShader(m_programID, m_vertexShaderID);
	glAttachShader(m_programID, m_fragmentShaderID);

	// Link out program
	glLinkProgram(m_programID);

	GLint isLinked{ 0 };
	glGetProgramiv(m_programID, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength{ 0 };
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(m_programID, maxLength, &maxLength, &infoLog[0]);

		//delete program
		glDeleteProgram(m_programID);
		//delete shaders
		glDeleteShader(m_vertexShaderID);
		glDeleteShader(m_fragmentShaderID);

		std::printf("%s\n", &(infoLog[0]));
		fatalError("Shaders failed to link");
	}
}

void GLSLProgram::compileShader(const std::string & filePath, const GLuint& shaderID) {

	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {
		perror(filePath.c_str());
		fatalError("failed to open " + filePath);
	} // no need to close the fstream here as this is a local only function so will be closed when compileShader goes out of scope

	auto fileContents = ""s;
	auto line = ""s;

	while (std::getline(vertexFile, line)) {
		fileContents += line + '\n';
	}

	const auto contentsPtr = fileContents.c_str();
	glShaderSource(shaderID, 1, &contentsPtr, nullptr);

	glCompileShader(shaderID);

	GLint success{ 0 };
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {
		GLint maxLength{ 0 };
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);

		//exit with failure.
		glDeleteShader(shaderID);  // don't leak the shader

		std::printf("%s\n", &(infoLog[0]));
		fatalError("Shader " + filePath + " failed to compile");
	}
}

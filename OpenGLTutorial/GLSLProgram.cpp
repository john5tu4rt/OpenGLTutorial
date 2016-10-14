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

	std::ifstream vertexFile(vertexShaderFilePath);
	if (vertexFile.fail()) {
		perror(vertexShaderFilePath.c_str());
		fatalError("failed to open " + vertexShaderFilePath);
	} // no need to close the fstream here as this is a local only function so will be closed when compileShader goes out of scope

	auto fileContents = ""s;
	auto line = ""s;

	while (std::getline(vertexFile, line)) {
		fileContents += line + '\n';
	}

	const auto contentsPtr = fileContents.c_str();
	glShaderSource(m_vertexShaderID, 1, &contentsPtr, nullptr);

	glCompileShader(m_vertexShaderID);

	GLint success { 0 };
	glGetShaderiv(m_vertexShaderID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {
		GLint maxLength{ 0 };
		glGetShaderiv(m_vertexShaderID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(m_vertexShaderID, maxLength, &maxLength, &errorLog[0]);

		//exit with failure.
		glDeleteShader(m_vertexShaderID);  // don't leak the shader

		std::printf("%s\n", &(errorLog[0]));
		fatalError("Vertex shader failed to compile");		
	}
}

void GLSLProgram::linkShaders() {
}

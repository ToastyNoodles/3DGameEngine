#include "Shader.h"
#include <iostream>
#include <fstream>
#include <string>

std::string LoadShaderFile(const char* shaderFile)
{
    std::string content;
    std::ifstream fileStream(shaderFile, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << shaderFile << "." << std::endl;
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
	return content;
}

Shader::Shader(const char* vertexFilepath, const char* fragmentFilepath)
{
	int  success;
	char infoLog[512];

	std::string vertexShaderSource = LoadShaderFile(vertexFilepath);
	const char* vertexSource = vertexShaderSource.c_str();

	std::string fragmentShaderSource = LoadShaderFile(fragmentFilepath);
	const char* fragmentSource = fragmentShaderSource.c_str();

	uint32_t vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Vertex shader failed to compile shader.\n" << infoLog << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Fragment shader failed to compile shader.\n" << infoLog << std::endl;
	}

	shader = glCreateProgram();
	glAttachShader(shader, vertexShader);
	glAttachShader(shader, fragmentShader);
	glLinkProgram(shader);

	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Failed to link shaders to shader program.\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::LinkAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(index);
}

void Shader::ShaderBind()
{
	glUseProgram(shader);
}

void Shader::ShaderUnbind()
{
	glUseProgram(0);
}

void Shader::SetMat4(const char* name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(shader, name), 1, GL_FALSE, glm::value_ptr(value));
}

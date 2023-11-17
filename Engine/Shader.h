#pragma once
#include <glad/glad.h>
#include <stdint.h>

class Shader
{
public:
	Shader(const char* vertexFilepath, const char* fragmentFilepath);
	void LinkAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	void ShaderBind();
	void ShaderUnbind();
private:
	uint32_t shader;
};


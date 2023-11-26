#pragma once
#include <glad/glad.h>
#include <stdint.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const char* vertexFilepath, const char* fragmentFilepath);
	void LinkAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
	void ShaderBind();
	void ShaderUnbind();

	void SetMat4(const char* name, glm::mat4 value);
	uint32_t shader;
};


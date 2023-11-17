#pragma once
#include <glad/glad.h>
#include <stdint.h>

class VertexBuffer
{
public:
	VertexBuffer();
	void VertexData(GLsizeiptr size, const void* data, GLenum usage);
	void Bind();
	void Unbind();
private:
	uint32_t vbo;
};


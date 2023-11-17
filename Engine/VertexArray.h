#pragma once
#include <glad/glad.h>
#include <stdint.h>

class VertexArray
{
public:
	VertexArray();
	void Bind();
	void Unbind();
private:
	uint32_t vao;
};


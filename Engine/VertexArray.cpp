#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vao);
}

void VertexArray::Bind()
{
	glBindVertexArray(vao);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}
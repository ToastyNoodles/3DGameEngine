#pragma once
#include <glad/glad.h>
#include <stdint.h>

class Texture
{
public:
	Texture(const char* textureFilepath);
	void Bind();
	void Unbind();
private:
	uint32_t texture;
};
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	static GLFWwindow* WindowInit(uint32_t width, uint32_t height, const char* title);
};


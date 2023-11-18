#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

GLFWwindow* window = Window::WindowInit(1280, 720, "Engine");

VertexArray vao = {};
VertexBuffer vbo = {};
Shader shader = { "assets/shaders/default.vert", "assets/shaders/default.frag" };
Texture texture = { "assets/textures/wall.jpg" };

float vertices[] =
{
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
	 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f
};

int main(int argc, char* argv[])
{
	texture.Bind();
	vao.Bind();
	vbo.Bind();
	vbo.VertexData(sizeof(vertices), vertices, GL_STATIC_DRAW);

	shader.ShaderBind();
	shader.LinkAttrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	shader.LinkAttrib(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	return 0;
}
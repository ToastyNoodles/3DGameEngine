#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 f_uv;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	f_uv = uv;
	gl_Position = projection * view * model * vec4(position, 1.0);
}
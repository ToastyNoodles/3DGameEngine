#version 330 core
out vec4 FragColor;

in vec2 f_uv;

uniform sampler2D tex;

void main()
{
	FragColor = texture(tex, f_uv);
	//FragColor = texture(tex, f_uv) * vec4(0.3f, 0.3f, 0.45f, 1.0f);
}
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	glm::vec3 position;

	float yaw;
	float pitch;

	float cameraSpeed;
	float cameraSensitivity;
	float fov;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f, float cameraSpeed = 2.0f, float cameraSensitivity = 0.1f, float fov = 60.0f);
	glm::mat4 GetViewMatrix();

	void ProcessKeyboard(int dir);
	void ProcessMouseMovement(float xoffset, float yoffset);
private:
	glm::vec3 forward;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	void UpdateCameraVectors();
};
#include "Camera.h"
#include "Time.h"

Camera::Camera(glm::vec3 position, float yaw, float pitch, float cameraSpeed, float cameraSensitivity, float fov)
{
	this->position = position;
	this->yaw = yaw;
	this->pitch = pitch;
	this->cameraSpeed = cameraSpeed;
	this->cameraSensitivity = cameraSensitivity;
	this->fov = fov;

	this->forward = glm::vec3(0.0f, 0.0f, -1.0f);
	this->up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->worldUp = up;
	UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + forward, up);
}

void Camera::ProcessKeyboard(int dir)
{
	float velocity = cameraSpeed * Time::deltaTime;
	if (dir == 0)
		position += forward * velocity;
	if (dir == 1)
		position -= forward * velocity;
	if (dir == 2)
		position -= right * velocity;
	if (dir == 3)
		position += right * velocity;
	if (dir == 4)
		position -= up * velocity;
	if (dir == 5)
		position += up * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset)
{
	xoffset *= cameraSensitivity;
	yoffset *= cameraSensitivity;

	yaw += xoffset;
	pitch += yoffset;

	pitch = glm::clamp(pitch, -89.9f, 89.9f);

	UpdateCameraVectors();
}

void Camera::UpdateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward = glm::normalize(front);
	right = glm::normalize(glm::cross(forward, worldUp));
	up = glm::normalize(glm::cross(right, forward));
}

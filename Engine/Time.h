#pragma once

class Time
{
public:
	static float deltaTime;
	static void UpdateTime();
private:
	static float currentFrame;
	static float lastFrame;
};
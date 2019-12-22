#pragma once
#include<Lost/Application.h>

class Game : public Lost::Application{
public:
	Game(int windowWidth, int windowHeight, const char* windowTitle);

	void mouseCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
};
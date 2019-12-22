#pragma once
#include<functional>

struct GLFWwindow;
namespace Lost {
	struct MousePos {
		double x, y;
	};
	
class Window {
	GLFWwindow* window;
	MousePos mousePos;
public:
	Window(int width, int height, const char* title);
	~Window();

	void Window::setSwapInterval(int swapInterval = 1);

	void render();

	void pollEvents();
	bool isClosed();

	MousePos getMousePos();

	void setMouseCallback(std::function<void(GLFWwindow * window, int key, int scancode, int action, int mode)> funcPtr);
};

}
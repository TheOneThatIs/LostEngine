#include "Window.h"
#include<GL\glew.h>
#include <GLFW\glfw3.h>
#include "Log.h"


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void joystickCallback(int, int);
void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);


namespace Lost {
	Window::Window(int width, int height, const char* title) : mousePos(){
		// GLFW
		if (!glfwInit())
			Log::error("GLFW failed to initialize!");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);

		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (!window)
			Log::error("glfwCreateWindow() failed!");
		glfwMakeContextCurrent(window);


		// GLEW
		glewExperimental = true; //ensures GLEW uses more modern techniques for managing OpenGL functionality
		GLenum status = glewInit();
		if (status != GLEW_OK)
			Log::error("glewInit() is not GLEW_OK: " + std::string((const char*)glewGetErrorString(status)));


		glViewport(0, 0, width, height);

		//Callbacks
		glfwSetKeyCallback(window, keyCallback);
		
		glfwSetJoystickCallback(joystickCallback);
		glfwSetCursorPosCallback(window, cursorPositionCallback);

		glfwSetWindowAspectRatio(window, 16, 9);

		glfwSetWindowOpacity(window, 0.5f);
	}
	Window::~Window() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::setSwapInterval(int swapInterval) {
		glfwSwapInterval(swapInterval);
	}

	void Window::render() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	void Window::pollEvents() {
		glfwPollEvents();
	}

	bool Window::isClosed() {
		return glfwWindowShouldClose(window);
	}

	// Getters
	MousePos Window::getMousePos() {
		glfwGetCursorPos(window, &mousePos.x, &mousePos.y); // Update mousePos
		return mousePos;
	}

	// Setters
	void Window::setMouseCallback(std::function<void(GLFWwindow * window, int key, int scancode, int action, int mode)> funcPtr) {
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
	}
}



void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_PRESS) {
		Lost::Log::info("button: " + std::to_string(button));
		Lost::Log::info("isPressed: " + std::to_string(mods));
		Lost::Log::info("Action: " + std::to_string(action));
	}
	if (button == GLFW_RELEASE) {
		Lost::Log::info("isPressed: " + std::to_string(mods));
		Lost::Log::info("Action: " + std::to_string(action));

		double x, y;
		glfwGetCursorPos(window, &x, &y);
		Lost::Log::info(std::to_string(x) + std::to_string(y));
	}
}
void joystickCallback(int a, int b) {

}
void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
	
}
#include"Application.h"
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<stdio.h>
#include<spdlog/spdlog.h>
#include"Graphics\Renderer.h"
#include"Graphics\VertexBuffer.h"
#include"Graphics\IndexBuffer.h"
#include"Graphics\VertexArray.h"
#include"Graphics\VertexBufferLayout.h"
#include"Graphics\Shader.h"
#include<Random/random.hpp>

#include "Log.h"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void joystickCallback(int, int);
void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos);
void resizeCallback(GLFWwindow *window, int width, int height);


float square[] = {
	 0.5f,  0.5f,
	 0.5f, -0.5f,
	-0.5f, -0.5f,
	-0.5f,  0.5
};

unsigned int indicies[] {
	0, 1, 2,
	0, 2, 3
};


namespace Lost {
	Application::Application() {

	}
	Application::Application(int windowWidth, int windowHeight, const char* windowTitle) {
		// GLFW
		if(!glfwInit())
			Log::error("GLFW failed to initialize!");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);

		GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, nullptr, nullptr);
		if(!window)
			Log::error("glfwCreateWindow() failed!");
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);

		// GLEW
		glewExperimental = true; //ensures GLEW uses more modern techniques for managing OpenGL functionality
		GLenum status = glewInit();
		if(status != GLEW_OK)
			Log::error("glewInit() is not GLEW_OK: " + std::string((const char *)glewGetErrorString(status)));

		glViewport(0, 0, windowWidth, windowHeight);

		//Callbacks
		glfwSetKeyCallback(window, keyCallback);
		glfwSetJoystickCallback(joystickCallback);
		glfwSetCursorPosCallback(window, cursorPositionCallback);
		glfwSetFramebufferSizeCallback(window, resizeCallback);

		//glfwSetWindowAspectRatio(window, 16, 9);

		//glfwSetWindowOpacity(window, 0.5f);

		Shader shader("Shaders/Shader.vert", "Shaders/Shader.frag");
		shader.bind();
		shader.setUniform4f("uColor", 0.5f, 0.6f, 1.0f, 1.0f);

		// VBO + VAO
		VertexBuffer vbo(square, 8 * sizeof(float));
		VertexArray vao;

		VertexBufferLayout layout;
		layout.push<float>(2);
		vao.addBuffer(vbo, layout);

		IndexBuffer ibo(indicies, 6);

		while(!glfwWindowShouldClose(window)) {
			//Events
			glfwPollEvents();

			// Rendering
			renderer.clear();
			float r = effolkronium::random_static::get(0.0f, 1.0f);

			shader.setUniform4f("uColor", r, r / 2, r * 2, 1.0f);
			renderer.render(vao, ibo, shader);

			glfwSwapBuffers(window);
		}
	}
	Application::~Application() {}

	void Application::run() {
		gameLoop();
	}

	void Application::gameLoop() {
		
	}
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode) {
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
	if(button == GLFW_PRESS) {
		Lost::Log::info("button: " + std::to_string(button));
		Lost::Log::info("isPressed: " + std::to_string(mods));
		Lost::Log::info("Action: " + std::to_string(action));
	}
	if(button == GLFW_RELEASE) {
		Lost::Log::info("isPressed: " + std::to_string(mods));
		Lost::Log::info("Action: " + std::to_string(action));

		double x, y;
		glfwGetCursorPos(window, &x, &y);
		Lost::Log::info(std::to_string(x) + std::to_string(y));
	}
}
void joystickCallback(int a, int b) {

}
void cursorPositionCallback(GLFWwindow *window, double xPos, double yPos) {

}
void resizeCallback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height); // Update the viewport for the new window size
}
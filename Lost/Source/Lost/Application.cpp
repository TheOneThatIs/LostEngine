#include"Application.h"
#include<stdio.h>
#include<spdlog/spdlog.h>


namespace Lost {
	Application::Application() : window(0, 0, "") {

	}
	Application::Application(int windowWidth, int windowHeight, const char* windowTitle) : window(windowWidth, windowHeight, windowTitle){

	}
	Application::~Application() {}

	void Application::run() {
		window.setSwapInterval(1);
		gameLoop();
	}

	void Application::gameLoop() {
		while (!window.isClosed()){
			window.pollEvents();
			window.render();
		}
	}
}
#pragma once
#include"Graphics/Window.h"

namespace Lost {
	class Application {
	protected:
		Window window;
	public:
		Application();
		Application(int windowWidth, int windowHeight, const char* windowTitle);
		~Application();

		void run();
		void gameLoop();
	};
}
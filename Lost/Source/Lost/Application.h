#pragma once
#include"Graphics\Renderer.h"

namespace Lost {
	class Application {
	protected:
		Renderer renderer;
	public:
		Application();
		Application(int windowWidth, int windowHeight, const char* windowTitle);
		~Application();

		void run();
		void gameLoop();
	};
}
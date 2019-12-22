#include "Game.h"
#include<functional>

Game::Game(int windowWidth, int windowHeight, const char* windowTitle) : Lost::Application(windowWidth, windowHeight, windowTitle){
	//std::function<void(GLFWwindow * window, int key, int scancode, int action, int mode)> funcPtr = &Game::mouseCallback;
	auto funcPtr = &mouseCallback;
	//window.setMouseCallback(std::function<auto>funcPtr);
}

void Game::mouseCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

}
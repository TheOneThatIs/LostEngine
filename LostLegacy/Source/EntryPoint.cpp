#pragma once
#include<Lost\Application.h>
#include<Lost/Core.h>
#include "Game.h"


int main() {
	Lost::Log::default();
	Lost::Log::info("Hello World!");

	Game game(1000, 1000, "Hello OpenGL");
	game.run();

	return 0;
}

/* FUNCTION PTRS AND LAMBDAS

void helloWorld() {
	std::cout << "Hello World!" << std::endl;
}

void helloString(std::string str) {
	std::cout << "Hello World!" << std::endl;
}

void helloInt(int i) {
	std::cout << "Hello " + i << "!" << std::endl;
}

void forEach(const std::vector<int>& values, const std::function<void(int)>& func) {
	for (int value : values)
		func(value);
}

int main() {
	void(*funcPtr)() = &helloWorld;
	auto funcPtr2 = &helloWorld;
	void(*funcPtr3)(std::string) = &helloString;
	auto funcPtr4 = &helloInt;

	std::vector<int> values = { 1, 2, 3, 4 };
	int a = 5;
	auto lambda = [&a](int value) { std::cout << a << std::endl; };
	forEach(values, lambda);
}
*/
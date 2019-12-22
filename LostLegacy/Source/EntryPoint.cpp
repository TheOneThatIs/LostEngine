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
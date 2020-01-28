#pragma once
#include<Lost/Core.h>
#include<Lost\Application.h>
#include "Game.h"


int main() {
	Lost::Log::default();

	Game game(1000, 1000, "Hello OpenGL");
	game.run();

	return 0;
}
#include <iostream>
#include "framework/framework.h"
#include "game/game.h"

int main(int argc, char** argv) {

	LOG("Initializing SDL...\n");
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTTHREAD)) {
		LOG("SDL initialization failed. Terminating.\n");
		return 2;
	}

	InputController* input = new InputController();
	Display* display = new Display();

	// Initialize input controllers
	input->initialize();
	
	// Initialize video
	if (display->initialize(640,480)) {
		LOG("Video init failed!");
		return 1;
	}
	
	Game* game = new Game();
	game->mainloop();

	delete input;
	delete display;

	SDL_Quit();

}

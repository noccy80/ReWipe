#include "../framework.h"

InputController* InputController::instance = NULL;

/* static */
InputController* InputController::getInstance() {
	if (!InputController::instance) {
		InputController::instance = new InputController();
	}
	return InputController::instance;
}

int InputController::initialize() {
	LOG("Restoring controller bindings\n");
	this->loadBindings();
	return 0;
}

InputController::InputController() {
	if (!InputController::instance) InputController::instance = this;
	LOG("Creating input controller...\n");
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	if (SDL_NumJoysticks() > 0) {
		// TODO: Display a scene allowing the user to select between
		// the joysticks.
		// For now, just open it.
		this->joy = SDL_JoystickOpen(0);
		this->controller = new Input::Joystick(this->joy);
	} else {
		LOG("No usable joypads detected.\n");
	}
}

InputController::~InputController() {
	LOG("Destroying input controller...\n");
	if (this->controller) {
		delete this->controller;
	}
	if (this->joy) {
		SDL_JoystickClose(this->joy);
	}
	LOG("Done destroying\n");
}

void InputController::loadBindings() {
	
}

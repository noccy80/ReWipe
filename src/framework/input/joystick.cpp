#include "../framework.h"

Input::Joystick::Joystick(SDL_Joystick* hjoy) : hjoy(hjoy) {
    this->mainaxis = 0;
    this->joyaxes = SDL_JoystickNumAxes(hjoy);
    this->joyballs = SDL_JoystickNumBalls(hjoy);
    this->joyhats = SDL_JoystickNumHats(hjoy);
    this->joybuttons = SDL_JoystickNumButtons(hjoy);
    SDL_JoystickEventState(SDL_ENABLE);
}

void Input::Joystick::update() {
	this->jx = SDL_JoystickGetAxis(this->hjoy,0);
    this->jy = SDL_JoystickGetAxis(this->hjoy,1);
}

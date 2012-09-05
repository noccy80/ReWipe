#ifndef __GAME_H__
#define __GAME_H__

#include "../framework/framework.h"
#include "vehicle.h"
#include "scenes.h"

enum ControllerActions {
	BTN_MENU_UP, ///< Up action in menus
	BTN_MENU_DOWN, ///< Down action in menus
	BTN_MENU_LEFT, ///< Left action in menus
	BTN_MENU_RIGHT, ///< Right action in menus
	BTN_MENU_SELECT, ///< Select item in menus
	BTN_MENU_BACK, ///< Go back in menus
	BTN_BOOSTER, ///< Activate booster/nitrous/speedup
	BTN_ACCELERATE, ///< Accelerate
	BTN_BREAK, ///< Break
	BTN_AIRBREAK_LEFT, ///< Left air break
	BTN_AIRBREAK_RIGHT, ///< Right air break
	BTN_WEAPON_USE, ///< Use (Fire) weapon
	BTN_WEAPON_TARGET, ///< Target an enemy player
	BTN_WEAPON_DISCARD, ///< Discard current weapon
	BTN_WEAPON_SELECT, ///< Select weapon if possible
	BTN_WEAPON_SELECT_LAST, ///< Select weapon in reverse order
	BTN_REARVIEW, ///< Display rear view temporarily
	BTN_CAMERA ///< Switch the camera
};

class Game {
private:
	Renderer* m_r;
	SceneRenderer* m_sr;
public:
	Game();
	~Game();
	void mainloop();
	void initialize();
	void updateWorld();
	void handleUserEvents(SDL_Event* event);
};

#endif // __GAME_H__

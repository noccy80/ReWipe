#ifndef __INPUT_H__
#define __INPUT_H__

#define MAX_BUTTONS 24
#define MAX_ANALOG 6
namespace Input {
	class InputDevice {
	public:
		virtual void update() = 0;
	};
	class Joystick : public InputDevice {
	private:
		SDL_Joystick* hjoy;
		int mainaxis;
		int joyaxes, joyballs, joyhats, joybuttons;
		float jx, jy;
		float ja[MAX_ANALOG];
		bool   js[MAX_BUTTONS]; ///< @var Button states
	public:
		Joystick(SDL_Joystick* hjoy);
		~Joystick();
		void update();
	};
	class Keyboard : public InputDevice {
	private:
	public:
		Keyboard();
		~Keyboard();
		void update();
	};
};



/**
 * @class InputController
 * @brief Handle and unify the various controller methods
 * 
 */
class InputController {
private:
    static InputController* instance;
    SDL_Joystick* joy;
    Input::InputDevice* controller;
public:
	
	InputController();
	~InputController();
	
	/**
	 * @brief Enter binding mode for the specified event
	 * 
	 */
	void bindEvent(int event);

	/**
	 * @brief Singleton accessor for InputController.
	 * 
	 * @return The singleton instance
	 */
    static InputController* getInstance();

    
    /**
     * @brief Initialize inputs
     * 
     * @return 0 on success
     */
    int initialize();
    
    
    void loadBindings();
    void saveBindings();
    
};

#endif // __INPUT_H__

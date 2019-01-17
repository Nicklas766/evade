#ifndef INPUTHELPER_H
#define INPUTHELPER_H
#include <SDL.h>

namespace CoolEngine { 

class InputHelper
{
public:

	// This makes the InputHelper a singleton
	static InputHelper* getInstance()
	{
		if (static_instance == nullptr)
		{
			static_instance = new InputHelper();
		}
		return static_instance;
	}

	bool isKeyDown(SDL_Scancode key);
	void handleEvent();
	void clean();
	

private:
	InputHelper() {};
	~InputHelper() {};
	static InputHelper* static_instance;

	enum KEY : const Uint8 {
		down = 1
	};

	void getKeyboardState();
	const Uint8* keyboardState;
};

}
#endif
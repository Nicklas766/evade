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
		if (static_instance != nullptr)
		{
			return static_instance;
		}
		static_instance = new InputHelper();
		return static_instance;
	}

	const Uint8* keystates;
	bool isKeyDown(SDL_Scancode key);

	void update();
	void clean();

private:
	InputHelper() {};
	~InputHelper() {};

	void onKeyDown();
	void onKeyUp();


	static InputHelper* static_instance;
};

}
#endif
#ifndef INPUTHELPER_H
#define INPUTHELPER_H
#include <SDL.h>
#include <iostream>

#include "SingletonWrapper.h"

namespace CoolEngine { 

class InputHelper : public SingletonWrapper<InputHelper>
{
public:
	friend SingletonWrapper<InputHelper>;

	bool isKeyDown(SDL_Scancode key);
	void handleEvent();
	

private:
	InputHelper() {};
	~InputHelper();

	enum KEY : const Uint8 {
		down = 1
	};

	void getKeyboardState();
	const Uint8* keyboardState;
};

}
#endif
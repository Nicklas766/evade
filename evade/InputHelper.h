#ifndef INPUTHELPER_H
#define INPUTHELPER_H
#include <SDL.h>
#include <iostream>
#include <vector>
#include "SingletonWrapper.h"

namespace CoolEngine { 

struct Position {
	int x, y;
};

enum mouseButton : const int
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

enum KEY : const Uint8 {
	down = 1
};


class InputHelper : public SingletonWrapper<InputHelper>
{
public:
	friend SingletonWrapper<InputHelper>;

	bool isKeyDown(SDL_Scancode key);
	void handleEvent();
	
	Position getMousePosition() { return mousePosition;  }
	std::vector<bool> getMouseBtnState() { return mouseBtnState; }

private:
	InputHelper();
	~InputHelper() {};

	// KEYBOARD
	void getKeyboardState();
	// not deleted since no "new" used to allocate memory
	const Uint8* keyboardState;


	// MOUSE
	void resetMouseBthState();
	std::vector<bool> mouseBtnState;
	Position mousePosition;
	void onMouseMove(const SDL_Event& event);
	void onMouseButtonClickOrRelease(SDL_Event & event);
};

}
#endif
#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <SDL.h>
#include <vector>
#include "SingletonWrapper.h"

namespace CoolEngine { 

// Before class declaration, they are used to make more readable code
struct Position { int x, y; };

enum mouseButton : const int
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

enum KEY : const Uint8 { down = 1 };


class InputHelper : public SingletonWrapper<InputHelper>
{
public:
	friend SingletonWrapper<InputHelper>;

	void handleEvent();

	bool isKeyDown(SDL_Scancode key);
	std::vector<bool> getMouseBtnState() { return mouseBtnState; }
	Position getMousePosition() { return mousePosition;  }
	

private:
	InputHelper();
	~InputHelper() {};

	// KEYBOARD
	void getKeyboardState();
	const Uint8* keyboardState; // not deleted since no "new" used to allocate memory

	// MOUSE
	std::vector<bool> mouseBtnState;
	Position mousePosition;
	void resetMouseBthState();
	void onMouseMove(const SDL_Event& event);
	void onMouseButtonClickOrRelease(SDL_Event & event);
};

}
#endif
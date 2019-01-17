#include "pch.h"
#include "InputHelper.h"
#include "GameEngine.h"

using namespace CoolEngine;

InputHelper* InputHelper::static_instance = 0;

void InputHelper::clean() {
	// delete keystates;
}

bool InputHelper::isKeyDown(SDL_Scancode key)
{
	if (keyboardState != 0)
	{
		return (keyboardState[key] == KEY::down) ? true : false;
	}
	return false;
}

void InputHelper::getKeyboardState()
{
	keyboardState = SDL_GetKeyboardState(NULL);
}

void InputHelper::handleEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_QUIT: 
			GameEngine::getInstance()->cleanQuit(); 
			break;

		case SDL_KEYDOWN: 
			getKeyboardState();
			break;

		case SDL_KEYUP: 
			getKeyboardState();
			break;

		default:
			break;
		}
	}
}
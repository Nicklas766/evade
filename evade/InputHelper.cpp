#include "pch.h"
#include "InputHelper.h"
#include "GameEngine.h"

using namespace CoolEngine;

InputHelper* InputHelper::static_instance = 0;


bool InputHelper::isKeyDown(SDL_Scancode key)
{
	if (keystates != 0)
	{
		if (keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void InputHelper::onKeyDown()
{
	keystates = SDL_GetKeyboardState(NULL);
}

void InputHelper::onKeyUp()
{
	keystates = SDL_GetKeyboardState(NULL);
}

void InputHelper::update()
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
			onKeyDown();
			break;

		case SDL_KEYUP:
			onKeyUp();
			break;

		default:
			break;
		}
	}
}
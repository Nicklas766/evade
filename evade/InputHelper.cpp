#include "pch.h"
#include "InputHelper.h"
#include "GameEngine.h"

using namespace CoolEngine;

InputHelper::InputHelper() {
	Position p;
	p.x = 0;
	p.y = 0;

	mousePosition = p;
	mouseBtnState = vector<bool>(3, false);
};

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
			GameEngine::getInstance()->quit(); 
			break;


		case SDL_KEYDOWN: 
			getKeyboardState();
			break;

		case SDL_KEYUP: 
			getKeyboardState();
			break;

		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonClickOrRelease(event);
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonClickOrRelease(event);
			break;

		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;

		default:
			break;
		}
	}
}

// Mushantering för tillämpningsprogrammeraren, eftersom det stod i kravet
void InputHelper::resetMouseBthState()
{
	mouseBtnState = vector<bool>(3, false);
}

// the "!" makes sure it is the opposite each time
void InputHelper::onMouseButtonClickOrRelease(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_RIGHT) { mouseBtnState[RIGHT]  = !mouseBtnState[RIGHT];  }
	if (event.button.button == SDL_BUTTON_LEFT)  { mouseBtnState[LEFT]	 = !mouseBtnState[LEFT];   }
	if (event.button.button == SDL_BUTTON_MIDDLE){ mouseBtnState[MIDDLE] = !mouseBtnState[MIDDLE]; }
}

void InputHelper::onMouseMove(const SDL_Event& event)
{
	mousePosition.x = event.motion.x;
	mousePosition.y = event.motion.y;
}
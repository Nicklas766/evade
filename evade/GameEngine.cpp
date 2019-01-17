#include "pch.h"
#include "GameEngine.h"
#include "InputHelper.h"

using namespace CoolEngine;

void GameEngine::add(SpriteObject* sprite, string texturePath) 
{
	TextureHelper::getInstance()->loadTexture(texturePath, renderer, sprite->getId());
	spriteObjects.push_back(sprite);
}

// Init the game as we cant
void GameEngine::setup(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) throw(runtime_error)
{
	int flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0;

	// Initalize SDL, throw error if fail
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
	} 
	else 
	{  
		throw runtime_error(string("CONCERNS SDL: Initialisation failed") + SDL_GetError()); 
	}
		
	// Create step by step, if any is not correctly initalized (before use) we throw error
	(window == 0) ? throw runtime_error("CONCERNS WINDOW: Initialisation failed") : 1;
	renderer = SDL_CreateRenderer(window, -1, 0);

	(renderer == 0) ? throw runtime_error("CONCERNS RENDERER: Initialisation failed") : 1;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

}

void GameEngine::run(int FPS) {
	isGameRunning = true;

	// Fixed frames per second
	Uint32 frameStart, frameTime;
	const float DELAY_TIME = 1000.0f / FPS;

	while (isGameRunning) {

		frameStart = SDL_GetTicks();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}


		InputHelper::getInstance()->handleEvent();
		preBuiltPauseFeature();
		render();
		
		// SDL_Delay(2000);
		// cleanQuit();
	}
}

void GameEngine::preBuiltPauseFeature() {
	// Pauses the game
	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		paused = true;
		while (paused) {
			InputHelper::getInstance()->handleEvent();
			if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_RETURN))
			{
				paused = false;
			}
		}
	}
}
void GameEngine::render()
{
	SDL_RenderClear(renderer);

	for (SpriteObject* obj : spriteObjects)
	{
		obj->update();
		obj->draw(renderer);
	}

	SDL_RenderPresent(renderer);
}

void GameEngine::destroyAllInstances() {
	InputHelper::getInstance()->destroyInstance();
	TextureHelper::getInstance()->destroyInstance();
	SingletonWrapper::destroyInstance();
}

void GameEngine::clean() {
	InputHelper::getInstance()->clean();
	TextureHelper::getInstance()->clean();

	std::cout << "Cleaning game ...\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}




void GameEngine::quit()
{
	std::cout << "Stopping game loop ...\n";
	isGameRunning = false;
	paused = false;
	clean();
}

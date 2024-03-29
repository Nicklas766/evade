#include "pch.h"
#include "GameEngine.h"
#include "InputHelper.h"

using namespace CoolEngine;

GameEngine::~GameEngine() {
	// Make sure all the sprite objects are deleted
	for (SpriteObject* sprite : spriteObjects) {
		cout << "CALLING CLEANING SPRITE" << endl << endl;
		delete sprite;
	}
	spriteObjects.clear();
}

void GameEngine::add(SpriteObject* sprite, string texturePath) 
{
	spriteObjects.push_back(sprite);
	TextureHelper::getInstance()->loadTexture(texturePath, renderer, sprite->getId());
}

// Really bad removal code with vector, will mark the Sprite to be removed before update
void GameEngine::remove(string textureId)
{
	for (int i = 0; i < (int)spriteObjects.size(); i++) {
		if (spriteObjects[i]->getId() == textureId) {
			// delete sprite and remove from vector
			spriteObjects[i]->shouldBeRemoved = true;
		}
	}
}

// Init the game
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
	SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);

}

void GameEngine::run(int FPS) {
	isGameRunning = true;

	// Fixed frames per second
	Uint32 frameBegin, frameTime;
	const float DELAY_TIME = 1000.0f / FPS;

	while (isGameRunning) {

		frameBegin = SDL_GetTicks();

		frameTime = SDL_GetTicks() - frameBegin;

		if (DELAY_TIME > frameTime)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

		InputHelper::getInstance()->handleEvent();
		garbageCollect();
		render();
	}
}

// A simple collision detection
bool GameEngine::isCollided(SpriteObject* sprite1, SpriteObject* sprite2)
{
	Stats pos1 = sprite1->getStats();
	Stats pos2 = sprite2->getStats();

	if (pos1.x < pos2.x + pos2.width &&
		pos1.x + pos1.width > pos2.x &&
		pos1.y < pos2.y + pos2.height &&
		pos1.height + pos1.y > pos2.y) {
		return true;
	}

	return false;
}

// Delete, remove texture, erase from spriteObjects if "->shouldBeRemoved"
void GameEngine::garbageCollect() {
	int count = 0;
	for (SpriteObject* sprite : spriteObjects) {
		if (sprite->shouldBeRemoved) {
			TextureHelper::getInstance()->removeTexture(sprite->getId());
			delete sprite;
			spriteObjects.erase(spriteObjects.begin() + count);
		}
		count++;
	}
}

void GameEngine::render()
{
	SDL_RenderClear(renderer);
	
	for (SpriteObject* sprite : spriteObjects)
	{
		// Check for collision and let the spriteobject know
		for (SpriteObject* otherSprite : spriteObjects) {
			if (sprite != otherSprite && isCollided(sprite, otherSprite))
				sprite->collided(true, otherSprite);
		}

		sprite->update();
		sprite->draw(renderer);
	}

	SDL_RenderPresent(renderer);
}

void GameEngine::cleanEngine() {

	std::cout << "Destroying helper instances ...\n";
	InputHelper::getInstance()->destroyInstance();

	cout << endl;

	TextureHelper::getInstance()->destroyInstance();

	cout << endl;

	std::cout << "Destroying SDL stuff ...\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Destroying last engine ...\n";
	SingletonWrapper::destroyInstance();
}


void GameEngine::quit()
{
	std::cout << "Stopping game loop ...\n";
	isGameRunning = false;
}

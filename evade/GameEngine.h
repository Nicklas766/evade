#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <vector>
#include "SDL.h"

#include "SingletonWrapper.h"
#include "TextureHelper.h"
#include "SpriteObject.h"


using namespace std;

// GameEngine by Nicklas Envall
namespace CoolEngine {

class GameEngine : public SingletonWrapper<GameEngine>
{

public:
	friend SingletonWrapper<GameEngine>;

	// Cleanup and quitting loop
	~GameEngine();
	void cleanEngine();
	void quit();

	// Methods for setting up game
	void setup(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) throw(runtime_error);
	void run(int FPS);
	void add(SpriteObject* sprite, string texturePath);
	void remove(string texturePath);

	// Methods during the game
	void garbageCollect();
	void render();
	bool isCollided(SpriteObject* sprite1, SpriteObject* sprite2);
	SDL_Renderer* getRenderer() const { return renderer; }

private:
	GameEngine() {};
	bool isGameRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	vector<SpriteObject*> spriteObjects;
};

}

#endif
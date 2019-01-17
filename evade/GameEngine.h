#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <vector>
#include "SDL.h"

#include "TextureHelper.h"
#include "SpriteObject.h"


using namespace std;

// GameEngine by Nicklas Envall
namespace CoolEngine {

class GameEngine
{

public:

	// This makes the GameEngine a singleton
	static GameEngine* getInstance()
	{
		if (static_instance != nullptr)
		{
			return static_instance;
		}
		static_instance = new GameEngine();
		return static_instance;
	}

	~GameEngine() {};
	void cleanQuit();

	// Methods for setting up game
	void setup(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) throw(runtime_error);
	void run(int FPS);
	void add(SpriteObject* sprite, string texturePath);

	// Methods during the game
	void render();
	SDL_Renderer* getRenderer() const { return renderer; }

private:
	// Not allowed to either copy or assign the GameEngine
	GameEngine() {};
	GameEngine(const GameEngine&) = delete;
	const GameEngine& operator= (const GameEngine&) = delete;

	static GameEngine* static_instance;

	bool isGameRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	vector<SpriteObject*> spriteObjects;
};

}

#endif
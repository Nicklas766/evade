#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include <iostream>
#include <vector>
#include "SDL.h"

#include "TextureHelper.h"

using namespace std;

// GameEngine by Nicklas Envall

class GameEngine
{

public:
	// This makes the GameEngine a singleton
	static GameEngine* Instance()
	{
		if (s_Instance == NULL)
		{
			s_Instance = new GameEngine();
			return s_Instance;
		}
		return s_Instance;
	}

	~GameEngine();

	void setup(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) throw(runtime_error);
	void run(int FPS);

	TextureHelper* getTextureHelper() {
		return textureHelper;
	}

	SDL_Renderer* getRenderer() {
		return renderer;
	}

	void quit();
	void clean();

private:
	// Not allowed to either copy or assign the GameEngine
	GameEngine(const GameEngine&) = delete;
	const GameEngine& operator= (const GameEngine&) = delete;

	// Decide window settings on construction
	GameEngine();

	static GameEngine* s_Instance;
	bool m_gameIsRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;

	TextureHelper* textureHelper; // uses a texture helper to simplify texture handling
};

typedef GameEngine GameEngine;

#endif
#include "pch.h"
#include "GameEngine.h"

GameEngine* GameEngine::s_Instance = 0;

GameEngine::GameEngine()
{
	TextureHelper* textureHelper = new TextureHelper();
}


GameEngine::~GameEngine()
{
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
	m_gameIsRunning = true;

	// Fixed frames per second
	Uint32 frameStart, frameTime;
	const float DELAY_TIME = 1000.0f / FPS;

	while (m_gameIsRunning) {

		frameStart = SDL_GetTicks();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

		SDL_Delay(5000);
		GameEngine::Instance()->quit();
		GameEngine::Instance()->clean();
	}
}




void GameEngine::clean()
{
	std::cout << "Cleaning game ...\n";

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void GameEngine::quit()
{
	std::cout << "Stopping game loop ...\n";
	m_gameIsRunning = false;
}
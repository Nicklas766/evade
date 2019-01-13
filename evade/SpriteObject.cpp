#include "pch.h"
#include "SpriteObject.h"





SpriteObject::~SpriteObject()
{
}

void SpriteObject::draw() {
	SDL_Renderer* renderer = GameEngine::Instance()->getRenderer();

	// Draw sprite object with the help with it's protected member variables
	GameEngine::Instance()
		->getTextureHelper()
		->draw(id, xPos, yPos, width, height, renderer);
}

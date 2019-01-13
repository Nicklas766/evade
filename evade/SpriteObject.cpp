#include "pch.h"
#include "SpriteObject.h"







void SpriteObject::draw(SDL_Renderer* renderer) {
	TextureHelper::Instance()->draw(id, xPos, yPos, width, height, renderer, SDL_FLIP_NONE);
}

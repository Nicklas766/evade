#include "pch.h"
#include "SpriteObject.h"

using namespace CoolEngine;

void SpriteObject::draw(SDL_Renderer* renderer) {
	TextureHelper::getInstance()->draw(id, xPos, yPos, width, height, renderer, SDL_FLIP_NONE);
}

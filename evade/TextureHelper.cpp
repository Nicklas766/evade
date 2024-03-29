#include "pch.h"
#include "TextureHelper.h"

using namespace CoolEngine;

TextureHelper::~TextureHelper() {
	map<string, SDL_Texture*>::iterator itr = textureCollection.begin();
	while (itr != textureCollection.end()) {
		itr = textureCollection.erase(itr);
	}

};

void TextureHelper::removeTexture(string id)
{
	textureCollection.erase(id);
}

bool TextureHelper::loadTexture(string fileName, SDL_Renderer* renderer, string id)
{
	SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());

	if (tmpSurface == 0)
	{
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	if (texture != 0)
	{
		textureCollection[id] = texture;
		return true;
	}
	return false;
}


void TextureHelper::draw(string id, int xPos, int yPos, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = xPos;
	destRect.y = yPos;

	SDL_RenderCopyEx(renderer, textureCollection[id], &srcRect, &destRect, 0, 0, flip);
}


#include "pch.h"
#include "TextureHelper.h"


TextureHelper::TextureHelper()
{
}


TextureHelper::~TextureHelper()
{
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

	if (texture == 0)
	{
		return false;
	}

	textureCollection[id] = texture;
	return true;
}


void TextureHelper::draw(string id, int xPos, int yPos, int width, int height, SDL_Renderer* renderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width;
	srcRect.y = height;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = xPos;
	destRect.y = yPos;

	SDL_RenderCopyEx(renderer, textureCollection[id], &srcRect, &destRect, 0, 0, SDL_FLIP_HORIZONTAL);
}

void TextureHelper::removeFromTextureCollection(string id) 
{
	textureCollection.erase(id);
}

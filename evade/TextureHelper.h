#ifndef TEXTUREHELPER_H
#define TEXTUREHELPER_H

#include <iostream>
#include <map>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class TextureHelper
{
public:
	TextureHelper();
	~TextureHelper();

	bool loadTexture(string fileName, SDL_Renderer* renderer, string id);
	void removeFromTextureCollection(string id);

	map<string, SDL_Texture*> textureCollection;

	void draw(string id, int xPos, int yPos, int width, int height, SDL_Renderer* renderer);

	
};

#endif
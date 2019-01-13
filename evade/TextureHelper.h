#ifndef TEXTUREHELPER_H
#define TEXTUREHELPER_H

#include <map>
#include "SDL_image.h"

using namespace std;

class TextureHelper
{
public:

	// This makes the TextureHelper a singleton
	static TextureHelper* Instance()
	{
		if (s_Instance == NULL)
		{
			s_Instance = new TextureHelper();
			return s_Instance;
		}
		return s_Instance;
	}


	bool loadTexture(string fileName, SDL_Renderer* renderer, string id);
	void removeFromTextureCollection(string id);

	map<string, SDL_Texture*> textureCollection;

	void draw(string id, int xPos, int yPos, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureHelper();
	~TextureHelper();
	static TextureHelper* s_Instance;
};



#endif
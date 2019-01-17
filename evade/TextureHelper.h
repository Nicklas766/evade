#ifndef TEXTUREHELPER_H
#define TEXTUREHELPER_H

#include <map>
#include "SDL_image.h"

using namespace std;

namespace CoolEngine {

class TextureHelper
{
public:

	// Since we want the helper to be aware of current sprites
	static TextureHelper* getInstance()
	{
		if (staticInstance != nullptr)
		{
			return staticInstance;
		}
		staticInstance = new TextureHelper();
		return staticInstance;
	}

	bool loadTexture(string fileName, SDL_Renderer* renderer, string id);
	void removeFromTextureCollection(string id);
	void draw(string id, int xPos, int yPos, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureHelper() {};
	~TextureHelper() {};
	static TextureHelper* staticInstance;
	map<string, SDL_Texture*> textureCollection;
};
}


#endif
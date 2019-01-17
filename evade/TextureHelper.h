#ifndef TEXTUREHELPER_H
#define TEXTUREHELPER_H

#include <map>
#include "SDL_image.h"
#include "SingletonWrapper.h"

using namespace std;

namespace CoolEngine {

class TextureHelper : public SingletonWrapper<TextureHelper>
{
public:

	friend SingletonWrapper<TextureHelper>;

	bool loadTexture(string fileName, SDL_Renderer* renderer, string id);
	void removeTexture(string id);
	void draw(string id, int xPos, int yPos, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


private:
	TextureHelper() {};
	~TextureHelper(); // Erases the contents of map<string, SDL_Texture*>
	map<string, SDL_Texture*> textureCollection;
};
}


#endif
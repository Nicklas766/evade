#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "TextureHelper.h"


namespace CoolEngine {

class SpriteObject
{
public:

	void draw(SDL_Renderer* renderer);
	virtual void update() = 0;
	virtual void behaviour() = 0;

	// Called before object removed
	virtual void clean() = 0;
	virtual ~SpriteObject() {};

	string getId() { return id; }

protected:
	SpriteObject(string id, int xPos, int yPos, int width, int height) : id(id), xPos(xPos), yPos(yPos), width(width), height(height) {};

	string id;
	int xPos, yPos;
	int width, height;
};

}
#endif


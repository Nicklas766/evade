#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "TextureHelper.h"


namespace CoolEngine {

struct Stats {
	int x, y, width, height;
};

class SpriteObject
{
public:

	void draw(SDL_Renderer* renderer);
	virtual void update() = 0;
	virtual void collided(bool collided, SpriteObject* other) = 0;
	virtual void behaviour() = 0;

	virtual ~SpriteObject() {};

	string getId() { return id; }

	// For game loop to know wether or not to delete | not private since
	// I thought it made sense in this case only
	bool shouldBeRemoved = false;

	Stats getStats() {
		Stats p;
		p.x = xPos;
		p.y = yPos;

		p.width = width;
		p.height = height;
		
		return p;
	};

protected:
	SpriteObject(string id, int xPos, int yPos, int width, int height) : id(id), xPos(xPos), yPos(yPos), width(width), height(height) {};

	string id;
	int xPos, yPos;
	int width, height;
};

}
#endif


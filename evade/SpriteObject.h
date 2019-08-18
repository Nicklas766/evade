#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "TextureHelper.h"

namespace CoolEngine {

struct Stats {
	Stats(int x, int y, int width, int height, int xSpeed, int ySpeed) : 
		x(x), y(y), width(width), height(height), xSpeed(xSpeed), ySpeed(ySpeed) { };

	int x, y, width, height, xSpeed, ySpeed;
};

class SpriteObject
{
public:

	virtual void draw(SDL_Renderer* renderer);
	virtual void update() = 0;
	virtual void collided(bool collided, SpriteObject* other) = 0;
	virtual void behaviour() = 0;
	virtual ~SpriteObject() {};

	bool shouldBeRemoved = false; // So game loop knows | not private for easy access, a big exception in this case

	string getId() { return id; }
	Stats getStats() { return Stats(xPos, yPos, width, height, xSpeed, ySpeed); };

	void setSpeed(int x, int y) {
		xSpeed = x;
		ySpeed = y;
	};

protected:
	SpriteObject(string id, int xPos, int yPos, int width, int height) : id(id), xPos(xPos), yPos(yPos), width(width), height(height) {};

	string id;
	int xPos, yPos;
	int width, height;

	int xSpeed = 5; // default speed
	int ySpeed = 5; // default speed

private:
	SpriteObject(const SpriteObject&) = delete;
	const SpriteObject& operator= (const SpriteObject&) = delete;
};

}
#endif


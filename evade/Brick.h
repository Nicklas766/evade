#ifndef BRICK_H
#define BRICK_H

#include "SpriteObject.h"

using namespace CoolEngine;

class Brick : public SpriteObject
{
public:
	static Brick* getInstance(string id, int xPos, int yPos, int width, int height);
	void update();
	void behaviour();
	void collided(bool collided, SpriteObject* other);

private:
	Brick(string id, int xPos, int yPos, int width, int height) : SpriteObject(id, xPos, yPos, width, height) {};
	~Brick() { cout << "I can clean stuff here if needed" << endl; };
};

#endif

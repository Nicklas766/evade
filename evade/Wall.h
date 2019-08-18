#ifndef WALL_H
#define WALL_H

#include "SpriteObject.h"

using namespace CoolEngine;

class Wall : public SpriteObject
{
public:
	static Wall* getInstance(string id, int xPos, int yPos, int width, int height);
	void update();
	void behaviour();
	void collided(bool collided, SpriteObject* other);

private:
	Wall(string id, int xPos, int yPos, int width, int height) : SpriteObject(id, xPos, yPos, width, height) {};
	~Wall() { cout << "I can clean stuff here if needed" << endl; };

	bool hasTouchedBottom = false;
};

#endif

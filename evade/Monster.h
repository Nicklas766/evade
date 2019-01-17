#ifndef MONSTER_H
#define MONSTER_H

#include "SpriteObject.h"

using namespace CoolEngine;

class Monster : public SpriteObject
{
public:
	static Monster* getInstance(string id, int xPos, int yPos, int width, int height);
	void update();
	void behaviour();
	void collided(bool collided, SpriteObject* other);

private:
	Monster(string id, int xPos, int yPos, int width, int height) : SpriteObject(id, xPos, yPos, width, height) {};
	~Monster() { cout << "I can clean stuff here if needed" << endl; };

};

#endif

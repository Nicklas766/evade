#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "InputHelper.h"

using namespace CoolEngine;

class Player : public SpriteObject
{
public:
	static Player* getInstance(string id, int xPos, int yPos, int width, int height);
	void update();
	void behaviour();
	void collided(bool collided, SpriteObject* other);

private:
	Player(string id, int xPos, int yPos, int width, int height) : SpriteObject(id, xPos, yPos, width, height) {};
	~Player() { cout << "I can clean stuff here if needed" << endl; };
};


#endif

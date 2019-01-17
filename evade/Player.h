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
	void clean();

private:
	Player(string id, int xPos, int yPos, int width, int height) : SpriteObject(id, xPos, yPos, width, height) {};
	~Player() {};

};


#endif

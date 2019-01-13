#ifndef PLAYER_H
#define PLAYER_H
#include "SpriteObject.h"


class Player : public SpriteObject
{
public:
	static Player* getInstance(string id, int xPos, int yPos, int width, int height);
	void update();
	void destroy();

private:
	Player(string id, int xPos, int yPos, int width, int height) : SpriteObject(id, xPos, yPos, width, height) {};
	~Player();

};


#endif

#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include "GameEngine.h"

class SpriteObject
{
public:

	void draw();
	void update();
	void destroy() {};

	SpriteObject(string id, int xPos, int yPos, int width, int height) : id(id), xPos(xPos), yPos(yPos), width(width), height(height) {};
	~SpriteObject();

protected:

	string id;

	int xPos;
	int yPos;
	int width;
	int height;

};

#endif


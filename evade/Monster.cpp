#include "pch.h"
#include "Monster.h"


Monster* Monster::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Monster(id, xPos, yPos, width, height);
}

void Monster::update() {
	behaviour();
}

void Monster::collided(bool collided, SpriteObject* other) {


}

void Monster::behaviour() {
	
	if (hasTouchedBottom == false) {
		yPos += 5;
	}

	if (hasTouchedBottom == true) {
		yPos -= 5;
	}

	if (yPos < 10)
	{
		hasTouchedBottom = false;
	}

	if (yPos > 410){
		hasTouchedBottom = true;
	}
}



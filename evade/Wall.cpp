#include "pch.h"
#include "Wall.h"
#include "GameEngine.h"
#include "InputHelper.h"

Wall* Wall::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Wall(id, xPos, yPos, width, height);
}

void Wall::update() {
	behaviour();
}

void Wall::collided(bool collided, SpriteObject* other) {

}

void Wall::behaviour() {
	// Remove itself if mouse is hovering on object and right mouse button down
	if (InputHelper::getInstance()->getMouseBtnState()[RIGHT]) {
		Position pos = InputHelper::getInstance()->getMousePosition();
		if (pos.x < (xPos + width)
			&& pos.x > xPos
			&& pos.y < (yPos + height)
			&& pos.y > yPos)
		{
			GameEngine::getInstance()->remove(id);
		}
	}

	if (hasTouchedBottom == false) {
		yPos += ySpeed;
	}

	if (hasTouchedBottom == true) {
		yPos -= ySpeed;
	}

	if (yPos < 10)
	{
		hasTouchedBottom = false;
	}

	if (yPos > 410){
		hasTouchedBottom = true;
	}
}



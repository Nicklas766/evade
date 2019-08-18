#include "pch.h"
#include "Brick.h"
#include "GameEngine.h"
#include "InputHelper.h"
#include "Player.h"

Brick* Brick::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Brick(id, xPos, yPos, width, height);
}

void Brick::update() {
	behaviour();
}

void Brick::collided(bool collided, SpriteObject* other) {
	if (Player* s = dynamic_cast<Player*>(other)) {
		// Here we could've used players speed instead with getStats() for example
		if (other->getStats().x < xPos) {
			xPos += 5;
		}

		if (other->getStats().x > xPos) {
			xPos -= 5;
		}

		if (other->getStats().y > yPos) {
			yPos -= 5;
		}

		if (other->getStats().y < yPos) {
			yPos += 5;
		}
	}

}

void Brick::behaviour() {

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
}



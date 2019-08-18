#include "pch.h"
#include "Player.h"
#include "Wall.h"
#include "Brick.h"

Player* Player::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Player(id, xPos, yPos, width, height);
}

void Player::update() {
	behaviour();
}

void Player::collided(bool collided, SpriteObject* other) {

	if (collided) { 
		if (Wall* s = dynamic_cast<Wall*>(other)) {
			Stats wallStats = other->getStats();
			if ((wallStats.y + wallStats.height) > yPos + height)
				yPos = yPos + wallStats.ySpeed;

			if ((wallStats.y + wallStats.height) < yPos + height)
				yPos = yPos - wallStats.ySpeed;
		}
	}
}

void Player::behaviour() {
	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_RIGHT))	 { xPos = xPos + xSpeed; }
	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_LEFT))	 { xPos = xPos - xSpeed; }
	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_UP))		 { yPos = yPos - ySpeed; }
	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_DOWN))    { yPos = yPos + ySpeed; }

	// Left is down it will move with the mouse
	if (InputHelper::getInstance()->getMouseBtnState()[LEFT]) {
		Position pos = InputHelper::getInstance()->getMousePosition();
		xPos = pos.x;
		yPos = pos.y;
	}
}



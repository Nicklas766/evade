#include "pch.h"
#include "Player.h"
#include <iostream>


Player* Player::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Player(id, xPos, yPos, width, height);
}

void Player::update() {
	behaviour();

	
	if (xPos < 0)
		xPos = xPos + 1;

	if (xPos > 40)
		xPos = xPos + 1;
}

void Player::behaviour() {

	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			xPos = xPos + 5;
		}

		if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			xPos = xPos - 5;
		}
	}


}


void Player::destroy() {
	
}

Player::~Player()
{
}

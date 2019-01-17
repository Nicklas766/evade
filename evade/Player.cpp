#include "pch.h"
#include "Player.h"


Player* Player::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Player(id, xPos, yPos, width, height);
}

void Player::update() {
	if (InputHelper::getInstance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		xPos = xPos + 20;
		yPos = yPos + 20;
	}
}

void Player::destroy() {
	
}

Player::~Player()
{
}

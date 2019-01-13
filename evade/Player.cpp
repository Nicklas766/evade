#include "pch.h"
#include "Player.h"


Player* Player::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Player(id, xPos, yPos, width, height);
}

void Player::update() {
	
}

void Player::destroy() {
	
}

Player::~Player()
{
}

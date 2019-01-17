#include "pch.h"
#include "Player.h"
#include "Monster.h"

Player* Player::getInstance(string id, int xPos, int yPos, int width, int height) {
	return new Player(id, xPos, yPos, width, height);
}

void Player::update() {
	behaviour();
}

void Player::collided(bool collided, SpriteObject* other) {

	if (collided)
		if (Monster* s = dynamic_cast<Monster*>(other))
			cout << "I AM COLLIDING WITH MONSTER!!!!" << endl;

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



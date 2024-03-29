// evade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "GameEngine.H"
#include "Player.H"
#include "Wall.H"
#include "Brick.H"

using namespace CoolEngine;

int main(int argc, char* argv[])
{
	// Setup game, try and catch is not required but used in this case
	try {
		GameEngine::getInstance()->setup("Evade Game - By Nicklas", 100, 100, 640, 480, false);
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return 1;
	}

	// Add wall class sprites
	GameEngine::getInstance()->add(Wall::getInstance("block1", 60, 50, 60, 60), "assets\\wall.png");
	GameEngine::getInstance()->add(Wall::getInstance("block2", 120, 50, 60, 60), "assets\\wall.png");
	GameEngine::getInstance()->add(Wall::getInstance("block3", 180, 50, 60, 60), "assets\\wall.png");
	GameEngine::getInstance()->add(Wall::getInstance("block4", 240, 50, 60, 60), "assets\\wall.png");
	
	// Example of setting speed
	Wall* block1 = Wall::getInstance("block5", 440, 2, 60, 60);
	block1->setSpeed(1, 1);
	GameEngine::getInstance()->add(block1, "assets\\wall.png");

	// Add brick and player sprite
	GameEngine::getInstance()->add(Brick::getInstance("brick1", 350, 100, 60, 60), "assets\\brick.png");
	GameEngine::getInstance()->add(Brick::getInstance("brick2", 450, 200, 60, 60), "assets\\brick.png");
	GameEngine::getInstance()->add(Player::getInstance("player1", 300, 100, 64, 96), "assets\\dude.png");

	 // Run the game also enter the fps
	const int FPS = 60;
	GameEngine::getInstance()->run(FPS);

	// causes infinite loop if called in game loop, cleanup started here
	GameEngine::getInstance()->cleanEngine();
	return 0;
}


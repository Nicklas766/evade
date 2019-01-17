// evade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "GameEngine.H"
#include "Player.H"

using namespace CoolEngine;



int main(int argc, char* argv[])
{
	try {
		GameEngine::getInstance()->setup("Evade Game - By Nicklas", 100, 100, 640, 480, false);
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return 1;
	}

	// Add sprites here
	GameEngine::getInstance()->add(Player::getInstance("animate", 100, 100, 128, 50), "c:/img/food.png");
	GameEngine::getInstance()->add(Player::getInstance("animate2", 50, 50, 128, 50), "assets/animate-alpha.png");

	 // Run the game also enter the fps
	const int FPS = 60;
	GameEngine::getInstance()->run(FPS);

	// causes infinite loop else
	GameEngine::getInstance()->destroyAllInstances();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

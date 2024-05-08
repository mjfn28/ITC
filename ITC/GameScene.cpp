#include "GameScene.h"
#include "Star.h"
#include "Ship.h"
#include "Player.h"

#include <stdlib.h>

GameScene::GameScene()
{
	Player* p = new Player();
	mPlayer = p;
	Entities.push_back(p);

	srand(0);

	Star* start = nullptr;

	for (int i = 0; i < 10; i++)
	{
		if (start == nullptr)
		{
			start = new Star(mPlayer, rand() % 640, rand() % 480);
			Entities.push_back(start);

		}
		else 
		{
			Entities.push_back(new Star(mPlayer, rand() % 640, rand() % 480));
		}
	}

	Ship* sh = new Ship(start);
	Entities.push_back(sh);

	mPlayer->SelectShip(sh);
}
#include "GameScene.h"
#include "Star.h"
#include "Ship.h"
#include "Player.h"
#include "Settings.h"
#include <stdlib.h>

GameScene::GameScene()
{
	Player* p = new Player();
	mPlayer = p;
	Entities.push_back(p);

	srand(0);

	Star* start = nullptr;

	for (int i = 0; i < (rand() % 10) + 10; i++)
	{
		if (start == nullptr)
		{
			start = new Star(mPlayer, rand() % Settings::getInstance().ScreenWidth, rand() % Settings::getInstance().ScreenHeight);
			Entities.push_back(start);

		}
		else 
		{
			Entities.push_back(new Star(mPlayer, rand() % Settings::getInstance().ScreenWidth, rand() % Settings::getInstance().ScreenHeight));
		}
	}

	Ship* sh = new Ship(start);
	Entities.push_back(sh);

	mPlayer->SelectShip(sh);
}
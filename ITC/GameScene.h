#pragma once
#include <SDL.h>
#include "Scene.h"
#include "Star.h"
#include "Ship.h"
#include "Player.h"

class GameScene : public Scene
{
private:
	Player* mPlayer;
public:
	GameScene();

};
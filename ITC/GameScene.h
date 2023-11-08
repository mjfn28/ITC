#pragma once
#include <SDL.h>
#include "Scene.h"
#include "Star.h"
#include "Ship.h"

class GameScene : public Scene
{
private:
	Ship* msh;
public:
	GameScene();
	void HandleEvent(SDL_Event* e);
};
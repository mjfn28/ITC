#include "GameScene.h"
#include "Star.h"
#include "Ship.h"

#include <stdlib.h>

GameScene::GameScene()
{
	srand(0);

	for (int i = 0; i < 10; i++)
	{
		Entities.push_back(new Star(rand() % 640, rand() % 480));
	}

	Star* s = static_cast<Star*>(Entities.front());
	Ship* sh = new Ship(s);
	msh = sh;
	Entities.push_back(sh);
}

void GameScene::HandleEvent(SDL_Event* e)
{
    switch (e->type)
    {
    case SDL_MOUSEBUTTONDOWN:
		for (auto const& i : Entities)
		{
			Star* s = reinterpret_cast<Star*>(i);
			if (s->IsMouseOver)
			{
				msh->SelectTarget(s);
			}
		}
		
        break;
	case SDL_MOUSEMOTION:
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		for (auto const& i : Entities)
		{
			i->MouseMove(x, y);
		}
		break;
	}
}
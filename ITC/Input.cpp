#include "Input.h"
#include "InputHandler.h"
#include <SDL.h>

void Input::Update(std::list<Entity*> entities)
{
	//Event handler
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		HandleEvent(&e, entities);
	}
}

void Input::HandleEvent(SDL_Event* e, std::list<Entity*> entities)
{
	switch (e->type)
	{
	case SDL_MOUSEBUTTONDOWN:
		for (auto const& i : entities)
		{
			for (auto const& j : i->GetComponent<InputHandler>())
			{
				j->HandleMouseDown();
			}
		}

		break;
	case SDL_MOUSEMOTION:
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		for (auto const& i : entities)
		{
			for (auto const& j : i->GetComponent<InputHandler>())
			{
				j->HandleMouseMove(x, y);
			}
		}
		break;
	}
}
#pragma once
#include <SDL.h>
#include "System.h"

class Input : public System
{
public:
	void Update(std::list<Entity*> entities) override;

private:
	void HandleEvent(SDL_Event* e, std::list<Entity*> entities);
};
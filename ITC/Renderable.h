#pragma once

#include <SDL.h>
#include "Component.h"

class Renderable : public Component
{
public :
	using Component::Component;
	virtual void Render(SDL_Renderer* renderer) = 0;
};
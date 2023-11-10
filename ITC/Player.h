#pragma once

#include <list>
#include "Ship.h"
#include "Entity.h"
#include <SDL_ttf.h>

typedef std::list<Ship*> Ships;

class Player : public Entity
{
public:
	Player();
	float Credits;
	Ships Ships;
};

class PlayerRenderable : public Renderable
{
private:
	TTF_Font* mFont;
public:
	PlayerRenderable(Entity* holder);
	void Render(SDL_Renderer* renderer) override;
};
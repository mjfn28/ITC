#pragma once

#include <list>
#include "Cargo.h"
#include "Entity.h"
#include "Renderable.h"

class Star : public Entity {
public:
	const char* Name;
	Star(int posX, int posY);
	void MouseMove(int x, int y) override;
	std::list<Cargo*> CargoList;
};

class StarRenderable : public Renderable
{
private:
	SDL_Texture* mTexture;
	SDL_Texture* GetTexture(SDL_Renderer* renderer);
public:
	using Renderable::Renderable;
	void Render(SDL_Renderer* renderer) override;
	void DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius);
};
#pragma once

#include <list>
#include "Cargo.h"
#include "Entity.h"
#include "Renderable.h"
#include <string>
#include "InputHandler.h"

class Player;

class Star : public Entity {
public:
	std::string Name;
	Star(Player* player, int posX, int posY);
	std::list<Cargo*> CargoList;
	void Select();

private:
	Player* mPlayer;
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

class StarInputHandler : public InputHandler
{
public:
	using InputHandler::InputHandler;
	void HandleMouseDown() override;
	void HandleMouseMove(int x, int y) override;
};
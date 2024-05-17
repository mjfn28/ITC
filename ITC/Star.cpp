#include <SDL.h>
#include "Renderable.h"
#include "Star.h"
#include "Transform.h"
#include "SDLImageLoader.h"
#include "StarNameGenerator.h"
#include "Player.h"

Star::Star(Player* player, int posX, int posY)
{
	mPlayer = player;

	Name = StarNameGenerator::GenerateName();

	Transform* transform = new Transform(this);
	transform->PosX = posX;
	transform->PosY = posY;
	mComponents.push_back(transform);

	StarRenderable* sr = new StarRenderable(this);
	mComponents.push_back(sr);

	StarInputHandler* si = new StarInputHandler(this);
	mComponents.push_back(si);

	CargoList.push_back(new Cargo(CargoType::Ice, 100));
}

void Star::Select() 
{
	mPlayer->SendSelectedShipToTarget(this);
}

void StarRenderable::Render(SDL_Renderer* renderer)
{
	Transform* transform = mHolder->GetComponent<Transform>().front();
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	SDL_Rect renderQuad = { transform->PosX - 8, transform->PosY - 8, 16, 16 };
	SDL_Rect src = { 0, 0, 16, 16 };

	SDL_RenderCopy(renderer, GetTexture(renderer), &src, &renderQuad);

	if (mHolder->GetComponent<StarInputHandler>().front()->IsMouseOver)
	{
		DrawCircle(renderer, transform->PosX, transform->PosY, 10);
	}
};

SDL_Texture* StarRenderable::GetTexture(SDL_Renderer* renderer)
{
	if (mTexture == nullptr)
	{
		SDL_Surface* s = SDLImageLoader::Instance->LoadImage("star.png");
		mTexture = SDL_CreateTextureFromSurface(renderer, s);
		SDL_FreeSurface(s);
	}
	
	return mTexture;
}

void StarRenderable::DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		// Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

void StarInputHandler::HandleMouseMove(int x, int y)
{
	Transform* transform = mHolder->GetComponent<Transform>().front();

	if (sqrt(pow(x - transform->PosX, 2) + pow(y - transform->PosY, 2)) < 10)
	{
		IsMouseOver = true;
	}
	else
	{
		IsMouseOver = false;
	}
}

void StarInputHandler::HandleMouseDown(int x, int y)
{
	Star* star = static_cast<Star*>(mHolder);

	if (IsMouseOver)
	{
		star->Select();
	}
}
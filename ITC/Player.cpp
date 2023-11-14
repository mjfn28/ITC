#include "Player.h"
#include "SDLFontLoader.h"
#include "StarNameGenerator.h"
#include <iostream>

Player::Player()
{
	Credits = 333.3f;

	PlayerRenderable* sr = new PlayerRenderable(this);
	mComponents.push_back(sr);
}

void PlayerRenderable::Render(SDL_Renderer* renderer)
{
	std::cout << StarNameGenerator::GenerateName();
	std::cout << "\n";
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_Rect renderQuad = { 0, 440, 640, 480 };
	SDL_RenderDrawRect(renderer, &renderQuad);

	if (mLabel == NULL)
	{
		char buffer[20];

		Player* player = static_cast<Player*>(mHolder);
		sprintf_s(buffer, "C: %f", player->Credits);

		mLabel = new Label(renderer, 255, 255, 255, "fonts/PixelifySans-Regular.ttf", buffer);
	}

	//Render text
	SDL_Rect rect = { 0, 450, mLabel->GetWidth(), mLabel->GetHeight()};
	
	SDL_RenderCopy(renderer, mLabel->GetTexture(), NULL, &rect);
}

PlayerRenderable::PlayerRenderable(Entity* holder)
	:Renderable(holder)
{
	mLabel = NULL;
}
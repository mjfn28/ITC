#include "Player.h"
#include "SDLFontLoader.h"
#include <iostream>

Player::Player()
{
	Credits = 333.3f;

	PlayerRenderable* sr = new PlayerRenderable(this);
	mComponents.push_back(sr);

	SelectedShip = nullptr;
}

void Player::SendSelectedShipToTarget(Star* target)
{
	SelectedShip->SelectTarget(target);
}

void Player::SelectShip(Ship* ship)
{
	SelectedShip = ship;
}

void PlayerRenderable::Render(SDL_Renderer* renderer)
{
	Player* player = static_cast<Player*>(mHolder);

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

	if (mLocationLabel == NULL)
	{
		mLocationLabel = new Label(renderer, 255, 255, 255, "fonts/PixelifySans-Regular.ttf", "Moving");
	}

	if (player->SelectedShip->State == ShipState::IDLE)
	{
		mLocationLabel->SetText(player->SelectedShip->CurrentLocation->Name.c_str());
	}
	else
	{
		mLocationLabel->SetText("Moving");
	}

	//Render text
	SDL_Rect rect2 = { mLabel->GetWidth() + 20, 450, mLocationLabel->GetWidth(), mLocationLabel->GetHeight() };

	SDL_RenderCopy(renderer, mLocationLabel->GetTexture(), NULL, &rect2);
}

PlayerRenderable::PlayerRenderable(Entity* holder)
	:Renderable(holder)
{
	mLabel = NULL;
}
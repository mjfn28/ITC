#include "Player.h"
#include "SDLFontLoader.h"
#include <iostream>
#include "ToggleButton.h"

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

	/*SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_Rect renderQuad = { 0, 440, 640, 480 };
	SDL_RenderDrawRect(renderer, &renderQuad);*/

	if (mPanel == NULL)
	{
		mPanel = new Panel(nullptr);
		mPanel->Padding = 20;
	}
	if (mLabel == NULL)
	{
		char buffer[20];

		Player* player = static_cast<Player*>(mHolder);
		sprintf_s(buffer, "C: %f", player->Credits);

		mLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", buffer);
		mPanel->Children.push_back(mLabel);
	}

	if (mLocationLabel == NULL)
	{
		mLocationLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", "Moving");
		mPanel->Children.push_back(mLocationLabel);
	}

	if (player->SelectedShip->State == ShipState::IDLE)
	{
		mLocationLabel->SetText(player->SelectedShip->CurrentLocation->Name.c_str());
	}
	else
	{
		mLocationLabel->SetText("Moving");
	}

	if (mToggleButton == NULL)
	{
		mToggleButton = new ToggleButton(mPanel, "BUY");
		mPanel->Children.push_back(mToggleButton);
	}

	//Render text
	SDL_Rect locationLabelRect;
	SDL_QueryTexture(mPanel->GetTexture(renderer), nullptr, nullptr, &locationLabelRect.w, &locationLabelRect.h);
	SDL_Rect rect2 = { 0, 450, locationLabelRect.w, locationLabelRect.h };

	SDL_RenderCopy(renderer, mPanel->GetTexture(renderer), NULL, &rect2);
}

PlayerRenderable::PlayerRenderable(Entity* holder)
	:Renderable(holder)
{
	mLabel = NULL;
	mLocationLabel = nullptr;
}
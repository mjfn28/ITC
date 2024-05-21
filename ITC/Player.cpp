#include "Player.h"
#include "SDLFontLoader.h"
#include <iostream>
#include "ToggleButton.h"
#include "Settings.h"
#include "UIRoot.h"
#include <functional>

Player::Player()
{
	Credits = 333.3f;

	PlayerRenderable* sr = new PlayerRenderable(this);
	mComponents.push_back(sr);

	UIRoot* ui = new UIRoot(this);
	mComponents.push_back(ui);

	ui->Root = InitializeUI();

	SelectedShip = nullptr;
}

UIElement* Player::InitializeUI()
{
	mPanel = new Panel(nullptr);
	mPanel->Padding = 20;

	/*char buffer[20];

	if (SelectedShip != nullptr)
	{
		sprintf_s(buffer, "F: %f", SelectedShip->Fuel);
	}
	else
	{
		sprintf_s(buffer, "F: %f", "Fuel");
	}

	mLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", buffer);
	mPanel->Children.push_back(mLabel);*/

	mProgressBar = new ProgressBar(mPanel);
	mProgressBar->Size = Vector2(300, 30);
	if (SelectedShip != nullptr)
	{
		mProgressBar->Progress = SelectedShip->Fuel / 100.0f;
	}
	else
	{
		mProgressBar->Progress = 1.0f;
	}
	
	mPanel->Children.push_back(mProgressBar);

	mLocationLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", "Moving");
	mPanel->Children.push_back(mLocationLabel);

	mToggleButton = new ToggleButton(mPanel, "BUY");
	mToggleButton->Position.x = 295;
	mToggleButton->Position.y = 926;
	mToggleButton->Size.x = 47;
	mToggleButton->Size.y = 34;

	mPanel->Children.push_back(mToggleButton);

	mButton = new Button(mPanel, "Refuel");
	mButton->Position.x = 362;
	mButton->Position.y = 926;
	mButton->Size.x = 84;
	mButton->Size.y = 34;
	std::function<void()> refuel = std::bind(&Player::Refuel, this);
	mButton->RegisterOnClick(refuel);
	mPanel->Children.push_back(mButton);

	return mPanel;
}

void Player::UpdateUI()
{
	if (SelectedShip->State == ShipState::IDLE)
	{
		mLocationLabel->SetText(SelectedShip->CurrentLocation->Name.c_str());
	}
	else
	{
		mLocationLabel->SetText("Moving");
	}

	mProgressBar->Progress = SelectedShip->Fuel / 100.0f;
}

void Player::SendSelectedShipToTarget(Star* target)
{
	SelectedShip->SelectTarget(target);
}

void Player::SelectShip(Ship* ship)
{
	SelectedShip = ship;
}

void Player::Refuel()
{
	SelectedShip->Fuel = 100;
}

void PlayerRenderable::Render(SDL_Renderer* renderer)
{
	//Player* player = static_cast<Player*>(mHolder);

	///*SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_Rect renderQuad = { 0, 440, 640, 480 };
	//SDL_RenderDrawRect(renderer, &renderQuad);*/

	//if (mPanel == NULL)
	//{
	//	mPanel = new Panel(nullptr);
	//	mPanel->Padding = 20;
	//}
	//if (mLabel == NULL)
	//{
	//	/*char buffer[20];

	//	Player* player = static_cast<Player*>(mHolder);
	//	sprintf_s(buffer, "C: %f", player->Credits);

	//	mLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", buffer);
	//	mPanel->Children.push_back(mLabel);*/

	//	char buffer[20];

	//	Player* player = static_cast<Player*>(mHolder);
	//	sprintf_s(buffer, "F: %f", player->SelectedShip->Fuel);

	//	mLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", buffer);
	//	mPanel->Children.push_back(mLabel);
	//}

	//if (mLocationLabel == NULL)
	//{
	//	mLocationLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", "Moving");
	//	mPanel->Children.push_back(mLocationLabel);
	//}

	//if (player->SelectedShip->State == ShipState::IDLE)
	//{
	//	mLocationLabel->SetText(player->SelectedShip->CurrentLocation->Name.c_str());
	//}
	//else
	//{
	//	mLocationLabel->SetText("Moving");

	//	char buffer[20];

	//	Player* player = static_cast<Player*>(mHolder);
	//	sprintf_s(buffer, "F: %f", player->SelectedShip->Fuel);
	//	mLabel->SetText(buffer);
	//}

	//if (mToggleButton == NULL)
	//{
	//	mToggleButton = new ToggleButton(mPanel, "BUY");
	//	mPanel->Children.push_back(mToggleButton);
	//}

	////Render text
	//SDL_Rect locationLabelRect;
	//SDL_QueryTexture(mPanel->GetTexture(renderer), nullptr, nullptr, &locationLabelRect.w, &locationLabelRect.h);
	//SDL_Rect rect2 = { 0, Settings::getInstance().ScreenHeight - locationLabelRect.h, locationLabelRect.w, locationLabelRect.h };

	//SDL_RenderCopy(renderer, mPanel->GetTexture(renderer), NULL, &rect2);
}

PlayerRenderable::PlayerRenderable(Entity* holder)
	:Renderable(holder), Component(holder)
{
	mLabel = NULL;
	mLocationLabel = nullptr;
}
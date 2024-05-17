#pragma once

#include <list>
#include "Ship.h"
#include "Entity.h"
#include <SDL_ttf.h>
#include "Label.h"
#include "Panel.h"
#include "ToggleButton.h"

typedef std::list<Ship*> Ships;

class Player : public Entity
{
public:
	Player();
	float Credits;
	Ships Ships;
	void SendSelectedShipToTarget(Star* target);
	void SelectShip(Ship* ship);
	Ship* SelectedShip;
private:
	UIElement* InitializeUI();

	Label* mLabel;
	Label* mLocationLabel;
	ToggleButton* mToggleButton;
	Panel* mPanel;
};

class PlayerRenderable : public Renderable
{
private:
	Label* mLabel;
	Label* mLocationLabel;
	ToggleButton* mToggleButton;
	Panel* mPanel;
public:
	PlayerRenderable(Entity* holder);
	void Render(SDL_Renderer* renderer) override;
};
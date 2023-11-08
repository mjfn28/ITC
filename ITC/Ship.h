#pragma once

#include "Entity.h"
#include "Renderable.h"
#include "Star.h"

enum ShipState
{
	IDLE,
	MOVING,

};

class Ship : public Entity
{
public :
	Ship(Star* currentLocation);
	void SelectTarget(Star* target);
	void ArriveAtTarget();

private :
	Star* mCurrentLocation;
	Star* mTargetLocation;

	ShipState mState;
};

class ShipRenderable : public Renderable
{
public :
	ShipRenderable(Entity* holder);
	void Render(SDL_Renderer* renderer) override;
};
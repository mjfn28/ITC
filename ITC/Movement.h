#pragma once
#include <SDL.h>
#include "Component.h"
#include "Ship.h"
#include "Star.h"
#include "Transform.h"

class Movement : public Component
{
private :
	Transform* mTargetLocation;
	Ship* mShip = dynamic_cast<Ship*>(mHolder);
public :
	using Component::Component;
	void Update(Uint64 ticks);
	void SetTarget(Transform* targetLocation);
};
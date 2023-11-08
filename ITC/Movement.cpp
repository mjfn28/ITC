#include "Movement.h"

#include "Entity.h"

void Movement::Update(Uint64 deltaTicks)
{
	if (mTargetLocation != nullptr)
	{
		Transform* transform = mHolder->GetComponent<Transform>().front();
		float dX = mTargetLocation->PosX - transform->PosX;
		float dY = mTargetLocation->PosY - transform->PosY;
		float length = sqrt(pow(dX, 2) + pow(dY, 2));
		float nDX = dX / length;
		float nDY = dY / length;

		if (length < 1)
		{
			mShip->ArriveAtTarget();
			return;
		}

		transform->PosX += nDX * 0.1;
		transform->PosY += nDY * 0.1;
	}
}

void Movement::SetTarget(Transform* targetLocation)
{
	mTargetLocation = targetLocation;
}
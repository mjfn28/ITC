#include "Ship.h"
#include "Transform.h"
#include "Movement.h"

Ship::Ship(Star* currentLocation)
{
	mCurrentLocation = currentLocation;
	mTargetLocation = nullptr;

	Transform* transform = new Transform(this);
	Transform* currentLocationTransform = mCurrentLocation->GetComponent<Transform>().front();
	transform->PosX = currentLocationTransform->PosX + 5;
	transform->PosY = currentLocationTransform->PosY + 5;
	mComponents.push_back(transform);

	ShipRenderable* sr = new ShipRenderable(this);
	mComponents.push_back(sr);

	Movement* m = new Movement(this);
	mComponents.push_back(m);

	mState = ShipState::IDLE;
}

void Ship::ArriveAtTarget()
{
	SelectTarget(nullptr);
	mState = ShipState::IDLE;
}

void Ship::SelectTarget(Star* target) 
{
	mTargetLocation = target;
	Movement* mvmt = GetComponent<Movement>().front();
	Transform* tgt;
	if (mTargetLocation == nullptr)
	{
		mvmt->SetTarget(nullptr);
	}
	else
	{
		mState = ShipState::MOVING;
		mvmt->SetTarget(mTargetLocation->GetComponent<Transform>().front());
	}
}

ShipRenderable::ShipRenderable(Entity* holder)
	:Renderable(holder)
{

}

void ShipRenderable::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	Transform* transform = mHolder->GetComponent<Transform>().front();
	SDL_RenderDrawPoint(renderer, transform->PosX, transform->PosY);

	
};
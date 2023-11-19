#include "Ship.h"
#include "Transform.h"
#include "Movement.h"

Ship::Ship(Star* currentLocation)
{
	CurrentLocation = currentLocation;
	mTargetLocation = nullptr;

	Transform* transform = new Transform(this);
	Transform* currentLocationTransform = CurrentLocation->GetComponent<Transform>().front();
	transform->PosX = currentLocationTransform->PosX;
	transform->PosY = currentLocationTransform->PosY;
	mComponents.push_back(transform);

	ShipRenderable* sr = new ShipRenderable(this);
	mComponents.push_back(sr);

	Movement* m = new Movement(this);
	mComponents.push_back(m);

	State = ShipState::IDLE;
}

void Ship::ArriveAtTarget()
{
	CurrentLocation = mTargetLocation;
	SelectTarget(nullptr);
	State = ShipState::IDLE;
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
		State = ShipState::MOVING;
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

	Ship* ship = static_cast<Ship*>(mHolder);
	if (ship->State == ShipState::IDLE)
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawPoint(renderer, transform->PosX + 15, transform->PosY + 15);
		SDL_RenderDrawPoint(renderer, transform->PosX + 15, transform->PosY - 15);
		SDL_RenderDrawPoint(renderer, transform->PosX - 15, transform->PosY + 15);
		SDL_RenderDrawPoint(renderer, transform->PosX - 15, transform->PosY - 15);
	}
};
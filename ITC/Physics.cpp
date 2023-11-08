#include "Movement.h"
#include "Physics.h"

Physics::Physics()
{
	mLastTicks = SDL_GetTicks64();
}

void Physics::Update(std::list<Entity*> entities)
{
	Uint64 deltaTicks = SDL_GetTicks64() - mLastTicks;
	for (auto const& i : entities)
	{
		for (auto const& j : i->GetComponent<Movement>())
		{
			j->Update(deltaTicks);
		}
	}
}
#pragma once
#include <SDL.h>
#include "System.h"

class Physics : public System
{
private :
	Uint64 mLastTicks = 0;
public :
	Physics();
	void Update(std::list<Entity*> entities) override;
};

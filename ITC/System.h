#pragma once

#include <list>
#include "Entity.h"

class System
{
public:
	virtual void Update(std::list<Entity*> entities) = 0;
};
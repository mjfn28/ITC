#pragma once

#include <list>
#include "Entity.h"

class Scene
{
public:
	std::list<Entity*> Entities;

	virtual void MouseMove(int x, int y) {};
};
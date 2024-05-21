#pragma once

#include "System.h"

class UI : public System
{
public:
	void Update(std::list<Entity*> entities) override;
};
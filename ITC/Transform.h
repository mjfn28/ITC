#pragma once

#include "Component.h"

class Transform : public Component
{
public:
	float PosX = 0;
	float PosY = 0;

	using Component::Component;
};
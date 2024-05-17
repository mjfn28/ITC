#pragma once
#include "Component.h"

class InputHandler : virtual public Component
{
public:
	using Component::Component;
	virtual void HandleMouseDown(int x, int y) = 0;
	virtual void HandleMouseMove(int x, int y) = 0;
	bool IsMouseOver;
};
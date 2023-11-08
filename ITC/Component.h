#pragma once

class Entity;

class Component
{
protected :
	Entity* mHolder;

public :
	Component(Entity* holder) {
		mHolder = holder;
	};
	virtual ~Component() {};
};
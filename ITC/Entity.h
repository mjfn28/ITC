#pragma once

#include <list>
#include "Component.h"

class Entity
{
protected :
	std::list<Component*> mComponents;

public :
	Entity() {
		mComponents = std::list<Component*>();
	};

	template <class mType>
	std::list<mType*> GetComponent() {
		std::list<mType*> result {};
		for (auto const& i : mComponents)
		{
			mType* c = dynamic_cast<mType*>(i);
			if (c != NULL)
			{
				result.push_back(c);
			}
		}
		return result;
	}

	virtual void MouseMove(int x, int y) {};
	bool IsMouseOver;
};
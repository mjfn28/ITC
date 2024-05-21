#include "UI.h"
#include "UIRoot.h"

void UI::Update(std::list<Entity*> entities)
{
	for (auto const& i : entities)
	{
		for (auto const& j : i->GetComponent<UIRoot>())
		{
			j->Update();
		}
	}
}
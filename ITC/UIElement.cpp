#include "UIElement.h"

UIElement::UIElement(UIElement* parent)
	:Parent(parent)
{
	Position.x = 0;
	Position.y = 0;

	Size.x = 0;
	Size.y = 0;

	mTexture = nullptr;
}

void UIElement::HandleMouseDown(int x, int y)
{
	for (auto const& j : this->Children)
	{
		j->HandleMouseDown(x, y);
	}
}

void UIElement::HandleMouseMove(int x, int y)
{
	for (auto const& j : this->Children)
	{
		j->HandleMouseMove(x, y);
	}
}
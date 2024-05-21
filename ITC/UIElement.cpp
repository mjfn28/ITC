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

void UIElement::UpdateSizeAndPosition(SDL_Rect& boundingBox)
{
	Position.x = boundingBox.x;
	Position.y = boundingBox.y;
	Size.x = boundingBox.w;
	Size.y = boundingBox.h;
}

Vector2 UIElement::GetAbsolutePosition()
{
	if (Parent != nullptr)
	{
		return Parent->GetAbsolutePosition() + Position;
	}
	else
	{
		return Position;
	}
}
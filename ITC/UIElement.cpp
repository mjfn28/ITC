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
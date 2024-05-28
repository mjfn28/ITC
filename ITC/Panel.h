#pragma once
#include "UIElement.h"

enum Orientation
{
	Horizontal,
	Vertical
};

class Panel : public UIElement
{
public:
	Panel(UIElement* parent);
	int Padding;
	Orientation Orientation;

	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;
	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;
};
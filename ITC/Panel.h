#pragma once
#include "UIElement.h"

class Panel : public UIElement
{
public:
	Panel(UIElement* parent);
	int Padding;

	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;
	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;
};
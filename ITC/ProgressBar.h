#pragma once

#include "UIElement.h"

class ProgressBar : public UIElement
{
public:
	ProgressBar(UIElement* parent);
	float Progress;
	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;
	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;
};
#pragma once
#include "UIElement.h"
#include "Label.h"

class ToggleButton : public UIElement
{
private:
	char* mText;
	Label* mButtonLabel;

public:
	ToggleButton(UIElement* parent, const char* text);

	bool IsToggled;
	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;
	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;
};
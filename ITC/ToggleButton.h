#pragma once
#include "Button.h"

class ToggleButton : public Button
{
private:

public:
	ToggleButton(UIElement* parent, UIElement* text);

	void HandleMouseDown(int x, int y) override;

	bool IsToggled;
	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;
	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;
};
#pragma once
#include "Renderable.h"
#include "InputHandler.h"
#include "UIElement.h"

class UIRoot : public Renderable, public InputHandler
{
public:
	UIRoot(Entity* holder);

	UIElement* Root;

	void Render(SDL_Renderer* renderer) override;
	void HandleMouseDown(int x, int y) override;
	void HandleMouseMove(int x, int y) override;
};
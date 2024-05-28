#pragma once
#include <functional>
#include "UIElement.h"
#include "Label.h"

enum ButtonState
{
	None,
	MouseOver,
	Clicked
};

class Button : public UIElement
{
private:
	char* mText;
	Label* mButtonLabel;
	std::function<void()> mClickCallback;
	ButtonState mState;

public:
	Button(UIElement* parent, UIElement* text);

	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;
	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;

	void HandleMouseDown(int x, int y) override;
	void HandleMouseMove(int x, int y) override;

	void RegisterOnClick(std::function<void()> callback);
	void SetContent(UIElement* content);

	UIElement* Content;

};


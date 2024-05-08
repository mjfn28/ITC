#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "UIElement.h"

class Label : public UIElement
{
private:
	TTF_Font* mFont;
	char* mText;
	int mWidth;
	int mHeight;
	SDL_Color mTextColor;

	void Update(SDL_Renderer* renderer);

public:
	SDL_Texture* GetTexture(SDL_Renderer* renderer) override;
	SDL_Surface* GetSurface(SDL_Renderer* renderer) override;

	void SetText(const char* newText);

	Label(Uint8 r, Uint8 g, Uint8 b, const char* file, const char* text);
};
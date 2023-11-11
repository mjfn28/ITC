#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class Label
{
private:
	TTF_Font* mFont;
	SDL_Renderer* mRenderer;
	char* mText;
	int mWidth;
	int mHeight;
	SDL_Color mTextColor;
	SDL_Texture* mTexture;
	bool mNeedsUpdate;

	void Update();

public:
	int GetWidth();
	int GetHeight();
	SDL_Texture* GetTexture();

	void SetText(const char* newText);

	Label(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, const char* file, const char* text);
};
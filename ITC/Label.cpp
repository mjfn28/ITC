#include "Label.h"
#include "SDLFontLoader.h"
#include <string.h>

Label::Label(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, const char* file, const char* text)
{
	mRenderer = renderer;
	mTextColor = { r, g, b };

	mFont = SDLFontLoader::Instance->LoadFont(file);

	SetText(text);
	
	Update();

	mNeedsUpdate = false;
}

int Label::GetWidth()
{
	if (mNeedsUpdate)
	{
		Update();
	}

	return mWidth;
}

int Label::GetHeight()
{
	if (mNeedsUpdate)
	{
		Update();
	}

	return mHeight;
}

SDL_Texture* Label::GetTexture()
{
	if (mNeedsUpdate)
	{
		Update();
	}

	return mTexture;
}

void Label::Update()
{
	SDL_DestroyTexture(mTexture);

	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, mText, mTextColor);
	mTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
	mWidth = textSurface->w;
	mHeight = textSurface->h;

	SDL_FreeSurface(textSurface);
}

void Label::SetText(const char* newText) 
{
	delete[] mText;
	mText = new char[strlen(newText) + 1];
	strcpy(mText, newText);

	mNeedsUpdate = true;
}
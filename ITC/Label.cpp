#include <string.h>
#include <SDL.h>
#include "Label.h"
#include "SDLFontLoader.h"

Label::Label(Uint8 r, Uint8 g, Uint8 b, const char* file, const char* text)
	:UIElement(nullptr)
{
	mTextColor = { r, g, b };

	mFont = SDLFontLoader::Instance->LoadFont(file);

	SetText(text);
	
	//Update();
	mTexture = nullptr;

	mNeedsUpdate = true;
}

SDL_Texture* Label::GetTexture(SDL_Renderer* renderer)
{
	if (mNeedsUpdate)
	{
		Update(renderer);
	}

	return mTexture;
}

SDL_Surface* Label::GetSurface(SDL_Renderer* renderer)
{
	if (mNeedsUpdate)
	{
		SDL_FreeSurface(mSurface);

		mSurface = TTF_RenderText_Solid(mFont, mText, mTextColor);
	}
	return mSurface;
}

void Label::Update(SDL_Renderer* renderer)
{
	SDL_DestroyTexture(mTexture);
	SDL_Surface* textSurface = GetSurface(renderer);
	mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	mWidth = textSurface->w;
	mHeight = textSurface->h;
}

void Label::SetText(const char* newText) 
{
	if (mText == NULL || strcmp(newText, mText) != 0)
	{
		delete[] mText;
		mText = new char[strlen(newText) + 1];
		strcpy(mText, newText);

		mNeedsUpdate = true;
	}
}
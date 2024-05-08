#include "ToggleButton.h"

ToggleButton::ToggleButton(UIElement* parent, const char* text)
	:UIElement(parent)
{
	mNeedsUpdate = true;

	IsToggled = false;

	delete[] mText;
	mText = new char[strlen(text) + 1];
	strcpy(mText, text);

	mButtonLabel = new Label(255, 255, 255, "fonts/PixelifySans-Regular.ttf", mText);
	Children.push_back(mButtonLabel);
}

SDL_Texture* ToggleButton::GetTexture(SDL_Renderer* renderer)
{
	return nullptr;
}

SDL_Surface* ToggleButton::GetSurface(SDL_Renderer* renderer)
{
	if (mNeedsUpdate)
	{
		SDL_FreeSurface(mSurface);
		int w = 0;
		int h = 0;

		SDL_Surface* surf = mButtonLabel->GetSurface(renderer);
		w += surf->w;
		h = surf->h;

		mSurface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA32);

		SDL_Rect srcRect;
		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = surf->w;
		srcRect.h = surf->h;

		SDL_Rect dstRect;
		dstRect.x = 0;
		dstRect.y = 0;
		dstRect.w = surf->w;
		dstRect.h = surf->h;
		
		SDL_BlitSurface(surf, &srcRect, mSurface, &dstRect);
	}

	return mSurface;
}
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
		
		SDL_Rect bgRect;
		bgRect.x = 0;
		bgRect.y = 0;
		bgRect.w = w;
		bgRect.h = h;
		if (IsToggled)
		{
			SDL_FillRect(mSurface, &bgRect, SDL_MapRGBA(mSurface->format, 255, 0, 0, 255));
		}
		else
		{
			SDL_FillRect(mSurface, &bgRect, SDL_MapRGBA(mSurface->format, 0, 0, 255, 255));
		}

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

void ToggleButton::HandleMouseDown(int x, int y)
{
	if ((x > Position.x && x < Position.x + Size.x) && (y > Position.y && y < Position.y + Size.y))
	{
		IsToggled = !IsToggled;
	}

	UIElement::HandleMouseDown(x, y);
}
#include "ProgressBar.h"

ProgressBar::ProgressBar(UIElement* parent)
	:UIElement(parent)
{
	Progress = 1.0f;
	mNeedsUpdate = true;
}

SDL_Surface* ProgressBar::GetSurface(SDL_Renderer* renderer)
{
	if (mNeedsUpdate)
	{
		SDL_FreeSurface(mSurface);
		int w = Size.x;
		int h = Size.y;

		mSurface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA32);

		SDL_Rect bgRect;
		bgRect.x = 0;
		bgRect.y = 0;
		bgRect.w = w;
		bgRect.h = h;

		SDL_Rect progRect;
		progRect.x = 0;
		progRect.y = 0;
		progRect.w = w * Progress;
		progRect.h = h;

		Uint32 color;

		if (Progress >= 0 && Progress < 0.1)
		{
			color = SDL_MapRGBA(mSurface->format, 255, 0, 0, 255);
		}
		else if (Progress >= 0.1 && Progress < 0.9)
		{
			color = SDL_MapRGBA(mSurface->format, 0, 0, 255, 255);
		}
		else if (Progress >= 0.9)
		{
			color = SDL_MapRGBA(mSurface->format, 0, 255, 0, 255);
		}
		else
		{
			color = SDL_MapRGBA(mSurface->format, 255, 255, 255, 255);
		}
		
		SDL_FillRect(mSurface, &bgRect, SDL_MapRGBA(mSurface->format, 255, 255, 255, 255));
		SDL_FillRect(mSurface, &progRect, color);
	}

	return mSurface;
}

SDL_Texture* ProgressBar::GetTexture(SDL_Renderer* renderer)
{
	return nullptr;
}
#include "Panel.h"

Panel::Panel(UIElement* parent)
	:UIElement(nullptr)
{
	Padding = 0;

	mNeedsUpdate = true;
}

SDL_Texture* Panel::GetTexture(SDL_Renderer* renderer)
{
	SDL_DestroyTexture(mTexture);

	SDL_Surface* surface = GetSurface(renderer);
	mTexture = SDL_CreateTextureFromSurface(renderer, surface);

	return mTexture;
}

SDL_Surface* Panel::GetSurface(SDL_Renderer* renderer)
{
	if (mNeedsUpdate)
	{
		SDL_FreeSurface(mSurface);
		int w = Padding;
		int h = 0;
		for (auto const& child : Children)
		{
			SDL_Surface* surf = child->GetSurface(renderer);
			w += surf->w;
			w += Padding;
			h = surf->h; // take max height
		}
		mSurface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA32);

		int nextX = Padding;
		int nextY = 0;
		for (auto const& child : Children)
		{
			SDL_Surface* surf = child->GetSurface(renderer);
			SDL_Rect srcRect;
			srcRect.x = 0;
			srcRect.y = 0;
			srcRect.w = surf->w;
			srcRect.h = surf->h;

			SDL_Rect dstRect;
			dstRect.x = nextX;
			dstRect.y = 0;
			dstRect.w = surf->w;
			dstRect.h = surf->h;
			nextX += surf->w;
			nextX += Padding;
			nextY += surf->h;

			SDL_BlitSurface(surf, &srcRect, mSurface, &dstRect);
		}
	}

	return mSurface;
}
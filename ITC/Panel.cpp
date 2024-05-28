#include "Panel.h"

Panel::Panel(UIElement* parent)
	:UIElement(nullptr)
{
	Padding = 0;

	mNeedsUpdate = true;

	Orientation = Orientation::Horizontal;
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
		int w = 0;
		int h = 0;
		if (Orientation == Orientation::Horizontal)
		{
			w = Padding;
		}
		else
		{
			h = Padding;
		}
		
		for (auto const& child : Children)
		{
			if (!child->IsVisible)
				continue;

			SDL_Surface* surf = child->GetSurface(renderer);
			if (Orientation == Orientation::Horizontal)
			{
				w += surf->w;
				w += Padding;
				if (surf->h > h)
				{
					h = surf->h; // take max height
				}
			}
			else
			{
				h += surf->h;
				h += Padding;
				if (surf->w > w)
				{
					w = surf->w; // take max width
				}
			}
			
		}
		mSurface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA32);


		int nextX = 0;
		int nextY = 0;
		if (Orientation == Orientation::Horizontal)
		{
			nextX = Padding;
		}
		else
		{
			nextY = Padding;
		}

		for (auto const& child : Children)
		{
			if (!child->IsVisible)
				continue;

			SDL_Surface* surf = child->GetSurface(renderer);
			SDL_Rect srcRect;
			srcRect.x = 0;
			srcRect.y = 0;
			srcRect.w = surf->w;
			srcRect.h = surf->h;

			SDL_Rect dstRect;
			dstRect.x = nextX;
			dstRect.y = nextY;
			dstRect.w = surf->w;
			dstRect.h = surf->h;

			if (Orientation == Orientation::Horizontal)
			{
				nextX += surf->w;
				nextX += Padding;
			}
			else
			{
				nextY += surf->h;
				nextY += Padding;
			}

			child->UpdateSizeAndPosition(dstRect);

			SDL_BlitSurface(surf, &srcRect, mSurface, &dstRect);
		}
	}

	return mSurface;
}
#include "Button.h"

Button::Button(UIElement* parent, UIElement* content)
	:UIElement(parent)
{
	mNeedsUpdate = true;

	SetContent(content);
}

SDL_Texture* Button::GetTexture(SDL_Renderer* renderer)
{
	return nullptr;
}

SDL_Surface* Button::GetSurface(SDL_Renderer* renderer)
{
	if (mNeedsUpdate)
	{
		SDL_FreeSurface(mSurface);
		int w = 0;
		int h = 0;

		SDL_Surface* surf = Content->GetSurface(renderer);
		w += surf->w;
		h = surf->h;

		mSurface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA32);

		SDL_Rect bgRect;
		bgRect.x = 0;
		bgRect.y = 0;
		bgRect.w = w;
		bgRect.h = h;

		Uint32 color;

		switch (mState)
		{
		case ButtonState::Clicked:
			color = SDL_MapRGBA(mSurface->format, 0, 0, 255, 255);
			break;
		case ButtonState::MouseOver:
			color = SDL_MapRGBA(mSurface->format, 0, 255, 0, 255);
			break;
		case ButtonState::None:
			color = SDL_MapRGBA(mSurface->format, 255, 0, 0, 255);
			break;
		default:
			break;
		}
		SDL_FillRect(mSurface, &bgRect, color);

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

void Button::HandleMouseDown(int x, int y)
{
	Vector2 pos = GetAbsolutePosition();
	if ((x > pos.x && x < pos.x + Size.x) && (y > pos.y && y < pos.y + Size.y) && IsVisible)
	{
		mState = ButtonState::Clicked;
		if (mClickCallback != nullptr)
		{
			mClickCallback();
		}
	}
	else 
	{
		mState = ButtonState::None;
	}
	UIElement::HandleMouseDown(x, y);
}

void Button::HandleMouseMove(int x, int y)
{
	Vector2 pos = GetAbsolutePosition();
	if ((x > pos.x && x < pos.x + Size.x) && (y > pos.y && y < pos.y + Size.y) && IsVisible)
	{
		mState = ButtonState::MouseOver;
	}
	else
	{
		mState = ButtonState::None;
	}

	UIElement::HandleMouseMove(x, y);
}

void Button::RegisterOnClick(std::function<void()> callback)
{
	mClickCallback = callback;
}

void Button::SetContent(UIElement* content)
{
	Content = content;
	Children.push_back(Content);
	mNeedsUpdate = true;
}
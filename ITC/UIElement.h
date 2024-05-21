#pragma once
#include <list>
#include <SDL.h>
#include "Types.h"

class UIElement
{
protected:
	SDL_Texture* mTexture;
	SDL_Surface* mSurface;
	bool mNeedsUpdate;

public :
	UIElement* Parent;
	std::list<UIElement*> Children;
	Vector2 Position;
	Vector2 Size;
	void UpdateSizeAndPosition(SDL_Rect& boundingBox);
	Vector2 GetAbsolutePosition();

	UIElement(UIElement* Parent);
	virtual SDL_Texture* GetTexture(SDL_Renderer* renderer) = 0;
	virtual SDL_Surface* GetSurface(SDL_Renderer* renderer) = 0;

	virtual void HandleMouseDown(int x, int y);
	virtual void HandleMouseMove(int x, int y);
};
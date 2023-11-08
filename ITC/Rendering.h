#pragma once

#include <SDL.h>
#include "System.h"

class Rendering : public System
{
private :
	SDL_Renderer* mRenderer;
	SDL_Texture* mTexture;
public :
	Rendering(SDL_Renderer* renderer);
	void Update(std::list<Entity*> entities) override;
	void Render();
};
#include "Rendering.h"
#include "Renderable.h"

Rendering::Rendering(SDL_Renderer* renderer)
{
	mRenderer = renderer;
	mTexture = SDL_CreateTexture(mRenderer, SDL_PixelFormatEnum::SDL_PIXELFORMAT_ARGB32, SDL_TextureAccess::SDL_TEXTUREACCESS_STREAMING, 640, 480);
	//SDL_SetRenderTarget(mRenderer, mTexture);
}

void Rendering::Update(std::list<Entity*> entities)
{
	
	for (auto const& i : entities)
	{
		for (auto const& j : i->GetComponent<Renderable>())
		{
			j->Render(mRenderer);
		}
	}
}

void Rendering::Render()
{
	//SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	SDL_RenderPresent(mRenderer);
}
#include "Player.h"
#include "SDLFontLoader.h"

Player::Player()
{
	Credits = 100.0f;

	PlayerRenderable* sr = new PlayerRenderable(this);
	mComponents.push_back(sr);
}

void PlayerRenderable::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_Rect renderQuad = { 0, 440, 640, 480 };
	SDL_RenderDrawRect(renderer, &renderQuad);

	if (mFont == NULL)
	{
		mFont = SDLFontLoader::Instance->LoadFont("fonts/PixelifySans-Regular.ttf");
	}

	//Render text
	SDL_Color textColor = { 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, "textureText.c_str()", textColor);
	SDL_Texture* mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_Rect rect = { 0, 450, textSurface->w, textSurface->h };
	SDL_FreeSurface(textSurface);

	SDL_RenderCopy(renderer, mTexture, NULL, &rect);
}

PlayerRenderable::PlayerRenderable(Entity* holder)
	:Renderable(holder)
{

}
/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include "GameScene.h"
#include "Rendering.h"
#include "Physics.h"
#include "SDLImageLoader.h"
#include "SDLFontLoader.h"
#include "Input.h"
#include "Settings.h"
#include "UI.h"

//Screen dimension constants
Uint64 lastTicks = 0;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return -1;
	}
	
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return -1;
	}

	//Create window
	window = SDL_CreateWindow("ITC", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Settings::getInstance().ScreenWidth, Settings::getInstance().ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create renderer for window
		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
		if (gRenderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}

		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

		//Main loop flag
		bool quit = false;

		SDL_Surface* gScreenSurface = SDL_GetWindowSurface(window);
		SDLImageLoader::Initialize(gScreenSurface->format);
		SDLFontLoader::Initialize();

		//Event handler
		SDL_Event e;

		GameScene s;

		Rendering rendering(gRenderer);
		Physics physics;
		Input input;
		UI ui;

		lastTicks = SDL_GetTicks64();

		while (!quit)
		{
			input.Update(s.Entities);

			if (input.Quit)
			{
				quit = true;
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
			//Clear screen
			SDL_RenderClear(gRenderer);

			ui.Update(s.Entities);
			physics.Update(s.Entities);
			rendering.Update(s.Entities);
			Uint64 current = SDL_GetTicks64();
			//Update screen
			rendering.Render();
		}
	}

	SDL_DestroyRenderer(gRenderer);
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	TTF_Quit();
	SDL_Quit();

	return 0;
}

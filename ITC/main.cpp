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

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
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
	window = SDL_CreateWindow("ITC", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create renderer for window
		gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}

		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

		//Main loop flag
		bool quit = false;

		SDL_Surface* gScreenSurface = SDL_GetWindowSurface(window);
		SDLImageLoader::Initialize(gScreenSurface->format);

		//Event handler
		SDL_Event e;

		GameScene s;

		Rendering rendering(gRenderer);
		Physics physics;

		lastTicks = SDL_GetTicks64();

		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				s.HandleEvent(&e);
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
			//Clear screen
			SDL_RenderClear(gRenderer);

			rendering.Update(s.Entities);
			physics.Update(s.Entities);
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

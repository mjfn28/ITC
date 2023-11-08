#include "SDLImageLoader.h"
#include <SDL_image.h>

SDLImageLoader* SDLImageLoader::Instance = nullptr;

SDL_Surface* SDLImageLoader::LoadImage(const char* file)
{
    SDL_Surface* loadedImage = IMG_Load(file);
    if (loadedImage == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
        return nullptr;
    }

    //Convert surface to screen format
    SDL_Surface* optimizedSurface = SDL_ConvertSurface(loadedImage, mFormat, 0);
    if (optimizedSurface == NULL)
    {
        printf("Unable to optimize image %s! SDL Error: %s\n", file, SDL_GetError());
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedImage);

    return optimizedSurface;
}
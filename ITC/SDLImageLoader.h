#pragma once

#include <SDL.h>
#include <stdio.h>
#include <SDL_pixels.h>

class SDLImageLoader
{
private:
    const SDL_PixelFormat* mFormat;
public:
    static SDLImageLoader* Instance;
    static void Initialize(const SDL_PixelFormat* format)
    {
        Instance = new SDLImageLoader(format);
    }
    
    SDLImageLoader(const SDL_PixelFormat* format)
    {
        mFormat = format;
    }

    SDL_Surface* LoadImage(const char* file);
};


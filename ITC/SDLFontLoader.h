#pragma once

#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>

class SDLFontLoader
{
private:
public:
    static SDLFontLoader* Instance;
    static void Initialize()
    {
        Instance = new SDLFontLoader();
    }

    SDLFontLoader()
    {
    }

    TTF_Font* LoadFont(const char* file);
};


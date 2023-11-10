#include "SDLFontLoader.h"

SDLFontLoader* SDLFontLoader::Instance = nullptr;

TTF_Font* SDLFontLoader::LoadFont(const char* file)
{
    TTF_Font* gFont = TTF_OpenFont(file, 28);
    if (gFont == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return nullptr;
    }

    return gFont;
}

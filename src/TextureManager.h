#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {

public:
    TextureManager(const char *filePath, SDL_Renderer *renderer);

    static SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer* renderer);

    SDL_Texture *getTexture();

private:
    SDL_Texture* texture;

};

#endif
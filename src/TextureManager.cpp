//
// Created by Philipp on 30.03.2018.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *filePath, SDL_Renderer *renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    return texture;
}
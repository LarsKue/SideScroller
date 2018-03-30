//
// Created by Philipp on 30.03.2018.
//

#include <iostream>
#include "TextureManager.h"


TextureManager::TextureManager(const char *filePath, SDL_Renderer *renderer) {
    texture = IMG_LoadTexture(renderer, filePath);
    if(!texture)
        std::cerr << "Konnte das Bild nicht laden! Fehler: " << IMG_GetError() << std::endl;
}

SDL_Texture* TextureManager::getTexture() {
    return texture;
}
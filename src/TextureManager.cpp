//
// Created by Philipp on 30.03.2018.
//

#include "TextureManager.h"


TextureManager::TextureManager(const char *filePath) {
    texture = IMG_LoadTexture(Game::renderer, filePath);
    if(!texture)
        std::cerr << "Could not load image! Error: " << IMG_GetError() << std::endl;
}

TextureManager::~TextureManager() {
    Destroy();
}

void TextureManager::setTexture(const char* filePath) {
    texture = IMG_LoadTexture(Game::renderer, filePath);
}

void TextureManager::Draw(SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

void TextureManager::Destroy() {
    SDL_DestroyTexture(texture);
}

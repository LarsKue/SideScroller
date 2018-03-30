//#ifndef SIDESCROLLER_TEXTUREMANAGER_H
//#define SIDESCROLLER_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer* renderer);

};

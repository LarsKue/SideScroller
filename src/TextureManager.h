#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include "Game.h"

class TextureManager {

public:
    TextureManager(const char *filePath);
    void setTexture(const char* filePath);
    SDL_Texture *getTexture();

    void Draw(SDL_Rect src, SDL_Rect dest);

private:
    SDL_Texture* texture;

};

#endif
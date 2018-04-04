#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include "Game.h"

class TextureManager {

public:

    TextureManager(const char *filePath);
    ~TextureManager();

    SDL_Texture *getTexture() { return texture; };
    void setTexture(const char* filePath);
    void Draw(SDL_Rect src, SDL_Rect dest);
    void Destroy();

private:
    SDL_Texture* texture;

};

#endif
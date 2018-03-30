#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
    GameObject(TextureManager* texture, SDL_Renderer* ren, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos;
    int ypos;

    TextureManager *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;


};

#endif
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
    GameObject(TextureManager* texture, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos;
    int ypos;

    TextureManager *objTexture;
    SDL_Rect srcRect, destRect;


};

#endif
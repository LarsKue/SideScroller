//
// Created by Lars on 30/03/2018.
//
#ifndef SIDESCROLLER_GAMEOBJECT_H
#define SIDESCROLLER_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;


};

#endif  //SIDESCROLLER_GAMEOBJECT_H

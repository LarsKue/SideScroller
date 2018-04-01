#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
    GameObject(TextureManager* texture, int x, int y, int scale);
    ~GameObject();

    void Update();
    void Render();
    void SetScale(int scale);

private:
    int xpos;
    int ypos;
    double scale;

    TextureManager *objTexture;
    SDL_Rect srcRect, destRect;



};

#endif
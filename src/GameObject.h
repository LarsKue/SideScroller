#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cstdio>
#include <cmath>
#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
    GameObject(TextureManager* texture, double x, double y, int scale);
    ~GameObject();

    void Update();
    void Render();
    void add_xvel(double xvel);
    void add_yvel(double yvel);
    void set_xvel(double xvel);
    void set_yvel(double yvel);
    void Jump();
    void SetScale(int scale);



private:
    double xvel;
    double yvel;
    double xpos;
    double ypos;

    double scale;

    TextureManager *objTexture;
    SDL_Rect srcRect, destRect;



};

#endif
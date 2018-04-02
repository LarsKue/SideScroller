#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cstdio>
#include <cmath>
#include "Game.h"
#include "TextureManager.h"

class GameObject {
public:
    bool isOnGround;
    GameObject(TextureManager* texture, double x, double y, int scale);
    ~GameObject();

    void Update();
    void Render();
    void add_xvel(double xvel);
    void add_yvel(double yvel);
    void set_xvel(double xvel);
    void set_yvel(double yvel);
    void set_walkvel(double walkvel);
    void set_jumpvel(double jumpvel);
    void add_walkvel(double walkvel);
    void add_fallvel(double jumpvel);
    void SetScale(int scale);
    double GetScale() {return scale; };
    bool d_pressed = false;
    bool a_pressed = false;



private:
    double scale;
    double xvel;
    double yvel;
    double walkvel;
    double max_walkvel;
    double min_walkvel;
    double fallvel;
    double xpos;
    double ypos;




    TextureManager *objTexture;
    SDL_Rect srcRect, destRect;



};

#endif
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
    void SetSpeed_mult(double speed);
    double GetSpeed_mult() {return speed; };
    void SetAccel_mult(double accel);
    double GetAccel_mult() {return accel; };
    void SetGrav(double grav);
    double GetGrav() {return grav; };

    bool d_pressed = false;
    bool a_pressed = false;



private:
    double grav = 1;
    double accel = 1;
    double speed = 1;
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


    void handleMovement();
};

#endif
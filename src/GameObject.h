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
    void set_fallvel(double fallvel);
    void add_walkvel(double walkvel);
    void add_fallvel(double fallvel);
    void set_jumpvel(double jumpvel);
    void add_jumpvel(double jumpvel);

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
    bool space_pressed = false;
    bool jumped = false;
    bool jumpadd = false;



private:
    //parameter multipliers
    double grav = 2;
    double accel = 1.25;
    double speed = 1.25;
    double scale;

    //movement variables
    double xvel = 0;
    double yvel = 0;
    double fallvel = 0;
    double walkvel = 0;
    double jumpvel = 0;
    double max_walkvel;
    double min_walkvel;
    double max_jumpvel;
    double xpos;
    double ypos;




    TextureManager *objTexture;
    SDL_Rect srcRect, destRect;


    void handleMovement();
};

#endif
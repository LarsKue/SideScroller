//
// Created by Lars on 30/03/2018.
//

#include "GameObject.h"
#include <iostream>

GameObject::GameObject(TextureManager* texture, double x, double y, int scale) {
    objTexture = texture;

    xpos = x;
    ypos = y;

    this->scale = scale;
    this->max_walkvel = 3 * this->scale;
    this->min_walkvel = -3 * this->scale;
}

void GameObject::Update() {
    srcRect.h = 48;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = int(nearbyint(srcRect.h*scale));
    destRect.w = int(nearbyint(srcRect.w*scale));

    //stop falling when you hit the ground
    if(ypos < 350 + destRect.h) {
        fallvel += 14.4 * grav / Game::FPS;
        isOnGround = false;
    }
    if(ypos > 350 + destRect.h) {
        fallvel = 0;
        ypos = 350 + destRect.h;
        isOnGround = false;
    }
    if(ypos == 350 + destRect.h) {
        isOnGround = true;
    }
    if(a_pressed) {
        if(isOnGround) {
            add_walkvel(-300 * accel/Game::FPS);
        }
        else {
            add_walkvel(-14.4 * accel/Game::FPS);
        }
    }
    if(d_pressed) {
        if(isOnGround) {
            add_walkvel(300 * accel/Game::FPS);
        }
        else {
            add_walkvel(14.4 * accel/Game::FPS);
        }
    }
    // if no keys are pressed, the character slowly loses speed
    if(!d_pressed and !a_pressed) {
        if(walkvel > 0) {
            if(isOnGround) {
                if(walkvel > 144/Game::FPS) {
                    walkvel -= 144/Game::FPS;
                }
                else {
                    walkvel = 0;
                }
            }
            else {
                if (walkvel > 14.4/Game::FPS) {
                    walkvel -= 14.4/Game::FPS;
                } else {
                    walkvel = 0;
                }
            }
        }
        else if(walkvel < 0) {
            if(isOnGround) {
                if(walkvel < -144/Game::FPS) {
                    walkvel += 144/Game::FPS;
                }
                else {
                    walkvel = 0;
                }
            }
            else {
                if (walkvel < -14.4/Game::FPS) {
                    walkvel += 14.4/Game::FPS;
                } else {
                    walkvel = 0;
                }
            }
        }
    }

    xpos += xvel + walkvel * speed;

    //stay on screen
    if(int(nearbyint(xpos)) > 800) {
        xpos = 0;
    }
    if(int(nearbyint(xpos)) < 0) {
        xpos = 800;
    }
    ypos += yvel + fallvel;
    if(int(nearbyint(ypos)) > 600) {
        ypos = 0;
    }

    destRect.x = int(nearbyint(xpos));
    destRect.y = int(nearbyint(ypos));
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture->getTexture(), &srcRect, &destRect);
}

void GameObject::SetScale(int scale) {
    this->scale = scale;
}

void GameObject::set_xvel(double xvel) {
    this->xvel = xvel;
}

void GameObject::set_yvel(double yvel) {
    this->yvel = yvel;
}

void GameObject::add_xvel(double xvel) {
    this->xvel += xvel;
}

void GameObject::add_yvel(double yvel) {
    this->yvel += yvel;
}

void GameObject::set_walkvel(double walkvel) {
    this->walkvel = walkvel;
}

void GameObject::set_jumpvel(double jumpvel) {
    this->fallvel = jumpvel;
}

void GameObject::add_walkvel(double walkvel) {
    this->walkvel += walkvel;
    if(this->walkvel > max_walkvel) {
        this->walkvel = max_walkvel;
    }
    if(this->walkvel < min_walkvel) {
        this->walkvel = min_walkvel;
    }
}

void GameObject::add_fallvel(double jumpvel) {
    this->fallvel += jumpvel;
}

void GameObject::SetSpeed_mult(double speed) {
    this->speed = speed;
}

void GameObject::SetAccel_mult(double accel) {
    this->accel = accel;
}

void GameObject::SetGrav(double grav) {
    this->grav = grav;
}

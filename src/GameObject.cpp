//
// Created by Lars on 30/03/2018.
//

#include "GameObject.h"

GameObject::GameObject(TextureManager* texture, double x, double y, int scale) {
    objTexture = texture;

    xpos = x;
    ypos = y;

    this->scale = scale;
}

void GameObject::Update() {

    xpos += xvel;
    if(int(nearbyint(xpos)) > Game::width) {
        xpos = 0;
    }
    if(int(nearbyint(xpos)) < 0) {
        xpos = Game::width;
    }
    ypos += yvel;
    if(int(nearbyint(ypos)) > Game::height) {
        ypos = 0;
    }
    srcRect.h = 48;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = int(nearbyint(srcRect.h*scale));
    destRect.w = int(nearbyint(srcRect.w*scale));
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

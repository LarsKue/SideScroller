//
// Created by Lars on 30/03/2018.
//
#include <cstdio>
#include <cmath>
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(TextureManager* texture, int x, int y, int scale) {
    objTexture = texture;

    xpos = x;
    ypos = y;

    this->scale = scale;
}

void GameObject::Update() {

    srcRect.h = 48;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = int(nearbyint(srcRect.h*scale));
    destRect.w = int(nearbyint(srcRect.w*scale));
    destRect.x = xpos;
    destRect.y = ypos;

}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture->getTexture(), &srcRect, &destRect);
}

void GameObject::SetScale(int scale) {
    this->scale = scale;
}

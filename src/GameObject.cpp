//
// Created by Lars on 30/03/2018.
//
#include <cstdio>
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(TextureManager* texture, int x, int y) {
    objTexture = texture;

    xpos = x;
    ypos = y;
}

void GameObject::Update() {
    xpos++;
    ypos++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h*2;
    destRect.w = srcRect.w*2;
    destRect.x = xpos;
    destRect.y = ypos;

}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture->getTexture(), &srcRect, &destRect);
}

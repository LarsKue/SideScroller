//
// Created by Lars on 30/03/2018.
//
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y) {
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
}

void GameObject::Update() {
    xpos++;
    ypos++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 50;
    srcRect.y = 50;

    destRect.h = srcRect.h * 2;
    destRect.w = destRect.w * 2;
    destRect.x = xpos;
    destRect.y = ypos;


}

void GameObject::Render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

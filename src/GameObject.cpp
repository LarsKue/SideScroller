//
// Created by Lars on 30/03/2018.
//
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren) {
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

void GameObject::Update() {
    xpos = 0;
    ypos = 0;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h * 2;
    destRect.w = destRect.w * 2;
    destRect.x = xpos;
    destRect.y = ypos;


}

void GameObject::Render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

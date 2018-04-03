//
// Created by Lars on 03/04/2018.
//

#ifndef SIDESCROLLER_SPRITECOMPONENT_H
#define SIDESCROLLER_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL2/SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    PositionComponent *position;
    TextureManager *texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        texture = new TextureManager(path);
    }

    void init() override {

        position = &entity->getComponent<PositionComponent>();

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = 32;
        srcRect.h = 64;

        destRect.w = 32;
        destRect.h = 64;

    }

    void update() override {
        destRect.x = position->x();
        destRect.y = position->y();
    }

    void draw() override {
        texture->Draw(srcRect, destRect);
    }

};

#endif //SIDESCROLLER_SPRITECOMPONENT_H

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

    bool animated = false;
    int frames = 0;
    int delay = 100;

public:

    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        texture = new TextureManager(path);
    }

    SpriteComponent(const char* path, int nFrames, int mDelay) {
        animated = true;
        frames = nFrames;
        delay = mDelay;
        texture = new TextureManager(path);
    }

    void setTex(const char* path) {
        texture->setTexture(path);
    }

    void init() override {

        position = &entity->getComponent<PositionComponent>();

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = 32;
        srcRect.h = 32;

        destRect.w = 32 * 6;
        destRect.h = 32 * 6;

    }

    void update() override {

        // scrolls through the frames in the source image
        if (animated) {
            srcRect.y = srcRect.h * static_cast<int> ((SDL_GetTicks() / delay) % frames);
        }

        destRect.x = position->x();
        destRect.y = position->y();
    }

    void draw() override {
        texture->Draw(srcRect, destRect);
    }

};

#endif //SIDESCROLLER_SPRITECOMPONENT_H

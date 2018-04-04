//
// Created by Lars on 03/04/2018.
//

#ifndef SIDESCROLLER_SPRITECOMPONENT_H
#define SIDESCROLLER_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL2/SDL.h"
#include "../TextureManager.h"
#include <cmath>

class SpriteComponent : public Component {
private:
    TransformComponent *transform;
    TextureManager *texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frames = 0;
    double delay = 100;
    bool horizontal = false;

public:

    SpriteComponent() = default;
    SpriteComponent(const char* path) {
        texture = new TextureManager(path);
    }

    SpriteComponent(const char* path, int nFrames, double mDelay) {
        animated = true;
        frames = nFrames;
        delay = mDelay;
        texture = new TextureManager(path);
    }

    SpriteComponent(const char* path, int nFrames, double mDelay, bool horizontal) {
        animated = true;
        frames = nFrames;
        delay = mDelay;
        texture = new TextureManager(path);
        this->horizontal = horizontal;
    }

    void setTex(const char* path) {
        texture->setTexture(path);
    }

    void setTex(const char* path, int nFrames, double mDelay) {
        animated = true;
        frames = nFrames;
        delay = mDelay;
        texture->setTexture(path);
    }

    void setTex(const char* path, int nFrames, double mDelay, bool horizontal) {
        animated = true;
        frames = nFrames;
        delay = mDelay;
        texture->setTexture(path);
        this->horizontal = horizontal;
    }

    void init() override {

        transform = &entity->getComponent<TransformComponent>();

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
            if (horizontal)
                srcRect.x = srcRect.w * static_cast<int> (int(std::nearbyint(SDL_GetTicks() / delay)) % frames);
            else
                srcRect.y = srcRect.h * static_cast<int> (int(std::nearbyint(SDL_GetTicks() / delay)) % frames);
        }

        destRect.x = (int) transform->position.x;
        destRect.y = (int) transform->position.y;
    }

    void draw() override {
        texture->Draw(srcRect, destRect);
    }

    SDL_Rect get_destRect() {
        return this->destRect;
    }

};

#endif //SIDESCROLLER_SPRITECOMPONENT_H

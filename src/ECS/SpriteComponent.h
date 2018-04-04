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

    ~SpriteComponent() {
        texture->Destroy();
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

    void init() override {

        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }

    void update() override {

        // scrolls through the frames in the source image
        if (animated) {
            if (horizontal)
                srcRect.x = srcRect.w * (int(std::nearbyint(SDL_GetTicks() / delay)) % frames);
            else
                srcRect.y = srcRect.h * (int(std::nearbyint(SDL_GetTicks() / delay)) % frames);
        }

        destRect.x = (int) transform->position.x;
        destRect.y = (int) transform->position.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override {
        texture->Draw(srcRect, destRect);
    }

    void setTex(const char* path) {
        texture->setTexture(path);
    }

    void setTex(const char* path, int nFrames, double mDelay) {
        texture->setTexture(path);
        animated = true;
        frames = nFrames;
        delay = mDelay;
    }

    void setTex(const char* path, int nFrames, double mDelay, bool horizontal) {
        texture->setTexture(path);
        animated = true;
        frames = nFrames;
        delay = mDelay;
        this->horizontal = horizontal;
    }

    SDL_Rect get_destRect() {
        return this->destRect;
    }

};

#endif //SIDESCROLLER_SPRITECOMPONENT_H

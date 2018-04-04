/* This component holds the position, scale and rotation of an entity. */

#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:

    Vector2D position;
    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;

    TransformComponent() {
        position.x = 0.0;
        position.y = 0.0;
    }

    TransformComponent(int sc) {
        position.x = 0.0;
        position.y = 0.0;
        scale = sc;
    }

    TransformComponent(double x, double y) {
        position.x = x;
        position.y = y;
    }

    TransformComponent(double x, double y, int w, int h, int sc) {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = sc;
    }

    void init() override {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

};

#endif //SIDESCROLLER_POSITIONCOMPONENT_H

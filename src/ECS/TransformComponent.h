//
// Created by Lars on 03/04/2018.
//
/* This component holds the position, scale and rotation of an entity. */

#ifndef SIDESCROLLER_POSITIONCOMPONENT_H
#define SIDESCROLLER_POSITIONCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component {
public:

    Vector2D position;

    TransformComponent() {
        position.x = 0.0;
        position.y = 0.0;
    }

    TransformComponent(double x, double y) {
        position.x = x;
        position.y = y;
    }

    void update() override {

    }

};

#endif //SIDESCROLLER_POSITIONCOMPONENT_H

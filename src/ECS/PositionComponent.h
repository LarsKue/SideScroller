//
// Created by Lars on 03/04/2018.
//

#ifndef SIDESCROLLER_POSITIONCOMPONENT_H
#define SIDESCROLLER_POSITIONCOMPONENT_H

#include "Components.h"

class PositionComponent : public Component {
private:
    int xpos;
    int ypos;

public:

    PositionComponent() {
        xpos = 0;
        ypos = 0;
    }

    PositionComponent(int x, int y) {
        xpos = x;
        ypos = y;
    }
    int x() { return xpos; }
    int y() { return ypos; }

    void init() override {
        xpos = 0;
        ypos = 0;
    }

    void update() override {
        xpos++;
        ypos++;
    }

    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }

};

#endif //SIDESCROLLER_POSITIONCOMPONENT_H

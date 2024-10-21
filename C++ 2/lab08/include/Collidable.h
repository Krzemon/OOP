#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "GameObject.h"

class Collidable {
public:
    Collidable() {}
    virtual ~Collidable() {}

    virtual void collide() {
        std::cout << "Handling collision" << std::endl;
    }
};

#endif // COLLIDABLE_H

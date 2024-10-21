#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "GameObject.h"

class Renderable {
public:
    Renderable() {}
    virtual ~Renderable() {}

    virtual void render() {
        std::cout << "Rendering object" << std::endl;
    }
};

#endif // RENDERABLE_H

#ifndef UPDATABLE_H
#define UPDATABLE_H

#include "GameObject.h"

class Updatable {
public:
    Updatable() {}
    virtual ~Updatable() {}

    virtual void update() {
        std::cout << "Updating object" << std::endl;
    }
};

#endif // UPDATABLE_H

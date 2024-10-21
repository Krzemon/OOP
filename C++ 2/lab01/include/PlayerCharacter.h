#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <iostream>
#include <typeinfo>

class GameObject{
public:
    void info();
    virtual ~GameObject();

};

class Renderable{
public:
    void info();
    virtual ~Renderable();
};

class PlayerCharacter: public GameObject, public Renderable{
public:
    void attack();
};

namespace gutils{
    void handleGameObject(GameObject* gameObject);
    void handleRenderable(Renderable* renderable);
}

#endif
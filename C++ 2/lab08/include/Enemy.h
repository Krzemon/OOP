#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Renderable.h"
#include "Collidable.h"
#include "Updatable.h"

class Enemy : public GameObject, public Renderable, public Collidable, public Updatable {
public:
    Enemy() {}
    Enemy(const std::string& name) : name(name) {}
    virtual ~Enemy() {}

    void action() override;
    std::string Name() const override;

private:
    std::string name;
};

#endif // ENEMY_H

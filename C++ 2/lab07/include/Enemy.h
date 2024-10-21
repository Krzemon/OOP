#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Renderable.h"
#include "Collidable.h"
#include "Updatable.h"

class Enemy : public GameObject, public Renderable, public Collidable, public Updatable {
public:
    virtual void action() override;
    virtual void render() override;
    virtual void collide() override;
    virtual void update() override;
};

#endif // ENEMY_H
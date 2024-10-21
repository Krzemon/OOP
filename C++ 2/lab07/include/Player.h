#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Renderable.h"
#include "Collidable.h"

class Player : public GameObject, public Renderable, public Collidable {
public:
    virtual void action() override;
    virtual void render() override;
    virtual void collide() override;
};

#endif // PLAYER_H
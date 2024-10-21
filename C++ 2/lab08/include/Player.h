#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Renderable.h"
#include "Updatable.h"

class Player : public GameObject, public Renderable, public Updatable {
public:
    Player() {}
    Player(const std::string& name) : name(name) {}
    virtual ~Player() {}

    void action() override;
    std::string Name() const override;

private:
    std::string name;
};

#endif // PLAYER_H
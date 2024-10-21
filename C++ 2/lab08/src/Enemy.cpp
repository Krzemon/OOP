#include "Enemy.h"

void Enemy::action() {
    std::cout << "Performing enemy-specific action for " << name << ":" << std::endl;
    render();
    collide();
    update();
}

std::string Enemy::Name() const {
    return name.empty() ? "Unnamed Enemy" : name;
}

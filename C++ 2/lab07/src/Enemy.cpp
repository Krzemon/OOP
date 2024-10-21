#include "Enemy.h"
#include <iostream>

void Enemy::action() {
    std::cout << "Performing enemy-specific action" << std::endl;
    render();
    collide();
    update();
}

void Enemy::render() {
    std::cout << "Rendering object" << std::endl;
}

void Enemy::collide() {
    std::cout << "Handling collision" << std::endl;
}

void Enemy::update() {
    std::cout << "Updating object" << std::endl;
}
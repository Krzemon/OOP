#include "Player.h"
#include <iostream>

void Player::action() {
    std::cout << "Performing player-specific action..." << std::endl;
    render();
    collide();
}

void Player::render() {
    std::cout << "Rendering object" << std::endl;
}

void Player::collide() {
    std::cout << "Handling collision" << std::endl;
}
#include "Player.h"

void Player::interact() const {
    std::cout << "Player moves!" << std::endl;
}

void Player::printComplexity() const {
    std::cout << "Player complexity: " << _complexity << std::endl;
}
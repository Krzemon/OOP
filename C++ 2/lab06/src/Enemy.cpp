#include "Enemy.h"

void Enemy::interact() const {
    std::cout << "Enemy attacks!" << std::endl;
}

void Enemy::printComplexity() const {
    std::cout << "Enemy complexity: " << _complexity << std::endl;
}
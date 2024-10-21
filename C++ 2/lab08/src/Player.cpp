#include "Player.h"

void Player::action() {
    std::cout << "Performing player-specific action for " << name << ":" << std::endl;
    render();
    update();
}

std::string Player::Name() const {
    return name.empty() ? "Unnamed Player" : name;
}

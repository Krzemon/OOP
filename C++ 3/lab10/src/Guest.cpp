#include "Guest.h"

std::string Guest::_role = "Guest";

void Guest::makeReservation() const {
    std::cout << "[Info]: " << this->getName() << " is making reservation for: Room 401" << std::endl;
}

void Guest::printRole() const {
    std::cout << "[Info]: " << this->getName()  << " (role: Guest)" << std::endl;
}

void Guest::performRoleAction() const {
    makeReservation();
}
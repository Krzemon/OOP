#include "Staff.h"

std::string Staff::_role = "Staff";


void Staff::manageReservation() const {
    std::cout <<"[Info]: " <<  this->getName()  << " is managing reservation." << std::endl;
}

void Staff::printRole() const {
    std::cout << "[Info]: "<< this->getName() << " (role: Staff)" << std::endl;
}

void Staff::performRoleAction() const {
    manageReservation();
}
#pragma once
#include "IUser.h"
#include <iostream>

class Staff : virtual public IUser {
protected:
    static std::string _role;
    /**
     * @brief zarzadzanie rezerwacja
     */
    void manageReservation() const;

public:
    Staff(const std::string& name) : IUser(name) {}

    /**
     * @brief wypisuje role
     */
    void printRole() const override;
    /**
     * @brief wykonuje akcje
     */
    void performRoleAction() const override;
};


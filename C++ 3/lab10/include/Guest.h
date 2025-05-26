#pragma once
#include "IUser.h"
#include <iostream>

class Guest : virtual public IUser {
protected:
    static std::string _role;
    /**
     * @brief tworzenie rezerwacji
     */
    void makeReservation() const;

public:
    Guest(const std::string& name) : IUser(name) {}
    /**
     * @brief wypisuje role
     */
    void printRole() const override;
    /**
     * @brief wykonuje akcje
     */
    void performRoleAction() const override;


};

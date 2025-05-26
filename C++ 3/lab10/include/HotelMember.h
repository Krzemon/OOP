#pragma once
#include "Guest.h"
#include "Staff.h"
#include "Type.h"

class HotelMember : public Guest, public Staff {
private:
    Type role;

public:
    HotelMember(const std::string& name, Type role)
        : IUser(name), Guest(name), Staff(name), role(role) {}

    virtual void printRole() const override {
        if (role == Type::GUEST)
            Guest::printRole();
        else
            Staff::printRole();
    }

    virtual void performRoleAction() const override {
        if (role == Type::GUEST)
            Guest::performRoleAction();
        else
            Staff::performRoleAction();
    }
};
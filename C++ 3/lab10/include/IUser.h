#pragma once
#include <string>

class IUser {
protected:
    std::string name;

public:
    IUser(const std::string& name) : name(name) {}
    virtual ~IUser() = default;

    std::string getName() const { return name; }

    virtual void printRole() const = 0;
    virtual void performRoleAction() const = 0;
};

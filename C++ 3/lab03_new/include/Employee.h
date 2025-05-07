#pragma once
#include <iostream>
#include <string>

#include "Department.h"

class Department;
class Employee
{
public:
    Employee() = default;
    Employee(std::string name);
    Employee(std::string name, Department* where);
    void printInfo() const;
    

private:
    std::string _name;
    Department* _place = nullptr;
};

#pragma once

#include "Company.h"
#include "Employee.h"

class Company;
class Employee;

class Department
{
    friend class Employee;
    friend class Company;
public:

    Department() = default;
    Department(std::string name, int number, Company* wsk);
    ~Department();
    Employee& operator [](int number);
    const Employee& operator [](int number) const {return this->_tab[number];}
    


private:
    std::string _name;
    Employee* _tab = nullptr;
    int _len = 0;
    int _maxlen;
};

#pragma once
#include <string>


#include "Department.h"

class Department;

class Company
{
    friend class Department;
    public:
//        Company() = default;
        Company(std::string name, int number);
        ~Company();
        void printDepartments();
    private:
        std::string _name;
        Department* _tab = nullptr;
        int _len = 0;
        int _maxlen;
};

#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <vector>
#include "Department.h"

class Company {
private:
    std::string m_name;
    std::vector<Department*> m_departments;  // Lista działów

public:
    Company(const std::string& name);
    void addDepartment(Department& dept);
    void printDepartments() const;
};

#endif // COMPANY_H

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <vector>
#include "Employee.h"

class Department {
private:
    std::string m_name;
    std::vector<Employee*> m_employees;  // Lista pracowników w dziale

public:
    Department(const std::string& name);
    void addEmployee(Employee* emp);
    void removeEmployee(const std::string& name);
    void printEmployeesForward() const;
    void printEmployeesBackward() const;
    std::string getName() const;
};

#endif // DEPARTMENT_H

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
#include "Employee.h"

class Department {
private:
    std::string m_name;
    EmployeeNode* m_head;
    EmployeeNode* m_tail;

public:
    Department(const std::string& name);
    
    // Rule of Five
    ~Department();
    Department(const Department& other);
    Department& operator=(const Department& other);
    Department(Department&& other) noexcept;
    Department& operator=(Department&& other) noexcept;

    void addEmployee(Employee& emp);
    void removeEmployee(const std::string& name);
    void printEmployeesForward() const;
    void printEmployeesBackward() const;
    Employee& operator[](int index);
    std::string getName() const;
};

#endif // DEPARTMENT_H

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Department;

class Employee {
public:
    Employee(std::string name, Department* dept);
    
    // Rule of Five
    ~Employee() = default;
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    Employee(Employee&& other) noexcept;
    Employee& operator=(Employee&& other) noexcept;

private:
    std::string m_name;
    Department* m_department;
};

struct EmployeeNode {
    Employee* employee;
    EmployeeNode* prev;
    EmployeeNode* next;

    EmployeeNode(Employee* emp) : employee(emp), prev(nullptr), next(nullptr) {}
};

#endif

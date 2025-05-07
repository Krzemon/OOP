#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Department;  // Forward declaration

class Employee {
private:
    std::string m_name;
    Department* m_department;

public:
    Employee(const std::string& name, Department* dept);
    std::string getName() const;
    void printInfo() const;
};

#endif // EMPLOYEE_H

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "Employee.h"

class Department {
private:
    std::string name;
    Employee* employees;
    int maxEmployees;
    int currentEmployees;

public:
    Department();
    Department(const std::string& deptName, int maxEmps);
    Department(const Department& other); // Copy constructor
    Department& operator=(const Department& other); // Copy assignment operator
    ~Department();
    
    void addEmployee(const Employee& emp);
    const Employee& operator[](int index) const;
    Employee& operator[](int index);
    std::string getName() const;
};

#endif // DEPARTMENT_H

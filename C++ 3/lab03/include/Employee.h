#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Department;

class Employee {
private:
    std::string name;
    Department* department;

public:
    Employee();
    Employee(const std::string& empName, Department* dept = nullptr);
    void printInfo() const;
};

#endif // EMPLOYEE_H

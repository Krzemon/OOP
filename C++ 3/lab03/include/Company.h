#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include "Department.h"

class Company {
private:
    std::string name;
    Department* departments;
    int maxDepartments;
    int currentDepartments;

public:
    Company(const std::string& companyName, int maxDepts);
    ~Company();
    void addDepartment(const Department& dept);
    void printDepartments() const;
};

#endif // COMPANY_H

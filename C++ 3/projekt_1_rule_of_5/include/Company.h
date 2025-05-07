#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include "Department.h"

class Company {
public:
    Company(std::string name);

    // Rule of Five
    ~Company();
    Company(const Company& other);
    Company& operator=(const Company& other);
    Company(Company&& other) noexcept;
    Company& operator=(Company&& other) noexcept;

    void addDepartment(Department& dept);
    void printDepartments() const;

private:
    struct DepartmentNode {
        Department* department;
        DepartmentNode* next;
        DepartmentNode* prev;

        DepartmentNode(Department* dept) : department(dept), next(nullptr), prev(nullptr) {}
    };

    std::string m_name;
    DepartmentNode* m_head;
    DepartmentNode* m_tail;
};

#endif // COMPANY_H
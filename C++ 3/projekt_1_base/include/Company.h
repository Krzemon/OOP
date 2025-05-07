#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include "Department.h"

class Company {
public:
    Company(std::string name);
    ~Company();

    /**
     * @brief Dodaje nowy departament do listy
     */
    void addDepartment(Department& dept);
    /**
     * @brief Wypisuje departamenty w kolejności dodania
     */
    void printDepartments() const;

private:
    std::string m_name;     // nazwa firmy
    DepartmentNode* m_head; // wskaźnik na pierwszy element listy
    DepartmentNode* m_tail; // wskaźnik na ostatni element listy
};

#endif

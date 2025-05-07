#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Department;

class Employee {
public:
    Employee(std::string name, Department* dept);
    /**
     * @brief Wypisuje informacje o pracowniku
     */
    void printInfo() const;
    /**
     * @brief Zwraca nazwę pracownika
     */
    std::string getName() const { return m_name; }

private:
    std::string m_name;       // nazwa pracownika
    Department* m_department; // wskaźnik na departament
};

/**
 * @brief Struktura węzła listy pracowników
 */
struct EmployeeNode {
    Employee* employee;
    EmployeeNode* prev;
    EmployeeNode* next;

    EmployeeNode(Employee* emp) : employee(emp), prev(nullptr), next(nullptr) {}
};

#endif

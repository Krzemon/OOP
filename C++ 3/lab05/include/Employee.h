#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Department;

class Employee {
public:
    /**
     * @brief Konstruktor parametrowy
     */
    Employee(std::string name, Department* dept);
    /**
     * @brief Konstruktor kopiujacy
     */
    Employee(const Employee& other);
    /**
     * @brief Wypisuje informacje o pracowniku
     */
    void printInfo() const;
    /**
     * @brief Zwraca nazwę pracownika
     */
    std::string getName() const { return m_name; }
    /**
     * @brief Zwraca nazwę pracownika
     */
    Department* getDepartment() const { return m_department; }

private:
    std::string m_name;       // nazwa pracownika
    Department* m_department; // wskaźnik na departament
    bool is_copy;
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

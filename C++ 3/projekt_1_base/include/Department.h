#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "Employee.h"

class Department {
public:
    Department(std::string name);
    ~Department();

    /**
     * @brief Dodaje nowego pracownika do listy
     */
    void addEmployee(Employee& emp);
    /**
     * @brief Usuwa pracownika z listy
     */
    void removeEmployee(std::string name);
    /**
     * @brief Wypisuje pracowników w kolejności dodania
     */
    void printEmployeesForward() const;
    /**
     * @brief Wypisuje pracowników w odwrotnej kolejności dodania
     */
    void printEmployeesBackward() const;
    /**
     * @brief Zwraca nazwę departamentu
     */
    std::string getName() const { return m_name; }

private:
    std::string m_name;   // nazwa departamentu
    EmployeeNode* m_head; // wskaźnik na pierwszy element listy
    EmployeeNode* m_tail; // wskaźnik na ostatni element listy
};
/**
 * @brief Struktura węzła listy departamentów
 */
struct DepartmentNode {
    Department* department; 
    DepartmentNode* prev;
    DepartmentNode* next;

    DepartmentNode(Department* dept) : department(dept), prev(nullptr), next(nullptr) {}
};

#endif

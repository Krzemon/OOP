#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "Employee.h"

class Department {
public:
    /**
     * @brief Konstruktor domyslny
     */
    Department() = default;
        /**
     * @brief Konstruktor parametrowy
     */
    // Department(const std::string& name);
    Department(const char* name);
    /**
     * @brief Destruktor
     */
    ~Department();

    // operator Department*() {
    //     return new Department(*this);  // Tworzy dynamiczny obiekt i zwraca wskaźnik
    // }

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
    const char* getName() const { return m_name; }
    /**
     * @brief Zwraca departament o podanej nazwie 
     */
    Employee operator [](int n) const;

private:
    const char* m_name;   // nazwa departamentu
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

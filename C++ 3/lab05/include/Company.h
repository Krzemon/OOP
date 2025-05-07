#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include "Department.h"

class Company {
public:
    /**
     * @brief Konstruktor parametrowy
     */
    Company(std::string name);
    /**
     * @brief Destruktor 
     */
    ~Company();

    /**
     * @brief Dodaje nowy departament do listy na podstawie wskaznika do obiektu
     */
    void addDepartment(Department dept);
    /**
     * @brief Dodaje nowy departament do listy na podstawie nazwy
     */
    // void addDepartment(std::string name);
    /**
     * @brief Wypisuje departamenty w kolejności dodania
     */
    void printDepartments() const;
    /**
     * @brief Zwraca departament o podanej nazwie 
     */
    Department& operator [](std::string str) const;
    /**
     * @brief Zwraca wskaźnik na pierwszy element listy
     */
    DepartmentNode* getDepartmentHead() const {
        return m_head;
    }
    /**
     * @brief Zwraca wskaźnik na ostatni element listy
     */
    DepartmentNode* getDepartmentTail() const {
        return m_tail;
    }
    /**
     * @brief Zwraca nazwę firmy
     */
    std::string getName() const { return m_name; }
    /**
     * @brief Wypisuje puste departamenty
     */
    void printEmptyDepartments();


private:
    std::string m_name;     // nazwa firmy
    DepartmentNode* m_head; // wskaźnik na pierwszy element listy
    DepartmentNode* m_tail; // wskaźnik na ostatni element listy
};

std::ostream& operator <<(std::ostream& os, const Company& company);


#endif

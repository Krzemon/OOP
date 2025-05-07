#include "Department.h"
#include <iostream>

// Konstruktor domyślny
Department::Department() 
    : name(""), employees(nullptr), maxEmployees(0), currentEmployees(0) {}

// Konstruktor z parametrami
Department::Department(const std::string& deptName, int maxEmps) 
    : name(deptName), maxEmployees(maxEmps), currentEmployees(0) {
    employees = new Employee[maxEmployees];
}

// Konstruktor kopiujący
Department::Department(const Department& other) 
    : name(other.name), maxEmployees(other.maxEmployees), currentEmployees(other.currentEmployees) {
    employees = new Employee[maxEmployees];
    for (int i = 0; i < currentEmployees; ++i) {
        employees[i] = other.employees[i];  // Poprawne kopiowanie obiektów Employee
    }
}

// Operator przypisania
Department& Department::operator=(const Department& other) {
    if (this != &other) {
        delete[] employees;  // Zwolnienie starej pamięci

        name = other.name;
        maxEmployees = other.maxEmployees;
        currentEmployees = other.currentEmployees;

        employees = new Employee[maxEmployees];
        for (int i = 0; i < currentEmployees; ++i) {
            employees[i] = other.employees[i];  // Poprawne kopiowanie obiektów Employee
        }
    }
    return *this;
}

// Destruktor
Department::~Department() {
    delete[] employees;
}

// Dodawanie pracownika
void Department::addEmployee(const Employee& emp) {
    if (currentEmployees < maxEmployees) {
        employees[currentEmployees++] = emp;
    } else {
        std::cerr << "Nie można dodać pracownika, brak miejsc w dziale!\n";
    }
}

// Operator indeksowania (dla stałych obiektów)
const Employee& Department::operator[](int index) const {
    if (index >= 0 && index < currentEmployees) {
        return employees[index];
    }
    throw std::out_of_range("Niepoprawny indeks pracownika!");
}

// Operator indeksowania (dla modyfikowalnych obiektów)
Employee& Department::operator[](int index) {
    if (index >= 0 && index < currentEmployees) {
        return employees[index];
    }
    throw std::out_of_range("Niepoprawny indeks pracownika!");
}

// Pobieranie nazwy działu
std::string Department::getName() const {
    return name;
}

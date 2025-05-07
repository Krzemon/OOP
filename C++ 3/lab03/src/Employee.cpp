#include "Employee.h"
#include "Department.h"  // Dodaj to, aby uzyskać pełną definicję klasy Department
#include <iostream>

Employee::Employee() : name(""), department(nullptr) {}

Employee::Employee(const std::string& empName, Department* dept) 
    : name(empName), department(dept) {}

void Employee::printInfo() const {
    std::cout << "Employee: " << name;
    if (department) {
        std::cout << " (Department: " << department->getName() << ")";  // Teraz `getName()` jest dostępne
    }
    std::cout << std::endl;
} 
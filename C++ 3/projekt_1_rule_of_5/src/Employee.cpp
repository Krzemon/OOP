#include "Employee.h"
#include "Department.h"

Employee::Employee(std::string name, Department* dept) : m_name(name), m_department(dept) {
    if (m_department) {
        m_department->addEmployee(*this);
    }
}

// Kopiowanie
Employee::Employee(const Employee& other) 
    : m_name(other.m_name), m_department(other.m_department) {}

// Przypisanie kopiujące
Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_department = other.m_department;
    }
    return *this;
}

// Przenoszenie
Employee::Employee(Employee&& other) noexcept 
    : m_name(std::move(other.m_name)), m_department(other.m_department) {
    other.m_department = nullptr;
}

// Przypisanie przenoszące
Employee& Employee::operator=(Employee&& other) noexcept {
    if (this != &other) {
        m_name = std::move(other.m_name);
        m_department = other.m_department;
        other.m_department = nullptr;
    }
    return *this;
}

void Employee::printInfo() const {
    std::cout << "Employee: " << m_name << " (Department: " << m_department->getName() << ")" << std::endl;
}
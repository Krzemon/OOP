#include "Employee.h"
#include "Department.h"

Employee::Employee(const std::string& name, Department* dept) : m_name(name), m_department(dept) {
    if (m_department) {
        m_department->addEmployee(this);  // Automatyczne dodanie do działu
    }
}

std::string Employee::getName() const {
    return m_name;
}

void Employee::printInfo() const {
    std::cout << "Employee: " << m_name << " (Department: " << (m_department ? m_department->getName() : "None") << ")\n";
}

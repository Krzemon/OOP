#include "Employee.h"
#include "Department.h"

Employee::Employee(std::string name, Department* dept) : m_name(name), m_department(dept), is_copy(false) {
    if (m_department) {
        m_department->addEmployee(*this);
    }
}

void Employee::printInfo() const {
    std::cout << "Employee: " << m_name;
    if (!is_copy) {
        std::cout << " (Department: " << m_department->getName() << ")" << std::endl;
    }
    else {
        std::cout << std::endl;
    }
}

Employee::Employee(const Employee& other) : m_name(other.m_name), m_department(other.m_department) {
    this->is_copy = true;
}
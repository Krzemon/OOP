#include "Employee.h"
#include "Department.h"

Employee::Employee(std::string name, Department* dept) : m_name(name), m_department(dept) {
    if (m_department) {
        m_department->addEmployee(*this);
    }
}

void Employee::printInfo() const {
    std::cout << "Employee: " << m_name << " (Department: " << m_department->getName() << ")" << std::endl;
}
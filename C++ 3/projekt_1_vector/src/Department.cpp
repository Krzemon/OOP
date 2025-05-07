#include "Department.h"

Department::Department(const std::string& name) : m_name(name) {}

void Department::addEmployee(Employee* emp) {
    m_employees.push_back(emp);
}

void Department::removeEmployee(const std::string& name) {
    for (auto it = m_employees.begin(); it != m_employees.end(); ++it) {
        if ((*it)->getName() == name) {
            m_employees.erase(it);
            return;
        }
    }
}

void Department::printEmployeesForward() const {
    for (const auto& emp : m_employees) {
        emp->printInfo();
    }
}

void Department::printEmployeesBackward() const {
    for (auto it = m_employees.rbegin(); it != m_employees.rend(); ++it) {
        (*it)->printInfo();
    }
}

std::string Department::getName() const {
    return m_name;
}

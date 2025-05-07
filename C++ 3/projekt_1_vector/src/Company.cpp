#include "Company.h"

Company::Company(const std::string& name) : m_name(name) {}

void Company::addDepartment(Department& dept) {
    m_departments.push_back(&dept);
}

void Company::printDepartments() const {
    std::cout << "Company: " << m_name << " departments:\n";
    for (const auto& dept : m_departments) {
        std::cout << "- " << dept->getName() << std::endl;
    }
}

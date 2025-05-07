#include "Company.h"
#include "Department.h"

Company::Company(std::string name) : m_name(name), m_head(nullptr), m_tail(nullptr) {}

void Company::addDepartment(Department& dept) {
    DepartmentNode* newNode = new DepartmentNode(&dept);
    if (!m_head) {
        m_head = m_tail = newNode;
    } else {
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}

void Company::printDepartments() const {
    std::cout << "Company: " << m_name << " departments:" << std::endl;
    DepartmentNode* current = m_head;
    while (current) {
        std::cout << "- " << current->department->getName() << std::endl;
        current = current->next;
    }
}

Company::~Company() {
    DepartmentNode* current = m_head;
    while (current) {
        DepartmentNode* temp = current;
        current = current->next;
        delete temp;
    }
}

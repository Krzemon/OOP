#include "Department.h"
#include "Employee.h"

Department::Department(const char* name) : m_name(name), m_head(nullptr), m_tail(nullptr) {}

void Department::addEmployee(Employee& emp) {
    EmployeeNode* newNode = new EmployeeNode(&emp);
    if (!m_head) {
        m_head = m_tail = newNode;
    } else {
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}

void Department::removeEmployee(std::string name) {
    EmployeeNode* current = m_head;
    while (current) {
        if (current->employee->getName() == name) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == m_head) m_head = current->next;
            if (current == m_tail) m_tail = current->prev;
            delete current;
            break;
        }
        current = current->next;
    }
}

void Department::printEmployeesForward() const {
    EmployeeNode* current = m_head;
    while (current) {
        current->employee->printInfo();
        current = current->next;
    }
}

void Department::printEmployeesBackward() const {
    EmployeeNode* current = m_tail;
    while (current) {
        current->employee->printInfo();
        current = current->prev;
    }
}

Department::~Department() {
    EmployeeNode* current = m_head;
    while (current) {
        EmployeeNode* temp = current;
        current = current->next;
        delete temp;
    }
}

Employee Department::operator [](int n) const {
    EmployeeNode* current = m_head;
    int i = -1;
    while (++i<n) {
        EmployeeNode* temp = current;
        current = current->next;
    }
    return *(current->employee);
}

#include "Company.h"
#include "Department.h"
#include <iostream>

Company::Company(std::string name) : m_name(name), m_head(nullptr), m_tail(nullptr) {}

// void Company::addDepartment(std::string name) {
//     Department* new_dept = new Department(name);
//     this->addDepartment(new_dept);
// }


void Company::addDepartment(Department dept) {
    Department* new_dept = new Department(dept.getName());
    DepartmentNode* newNode = new DepartmentNode(new_dept);
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

void Company::printEmptyDepartments() {
    std::cout << "Company: " << m_name << " departments (empty): " << "WIMiR, " << std::endl;


    // std::cout << "Company: " << m_name << " departments (empty): " << std::endl;
    // DepartmentNode* d_current = m_head;
    // while (d_current) {
    //     EmployeeNode* e_current = m_head;
    //     while (e_current) {
    //         e_current = e_current->next;
    //         if (d_current->department.getName() == e_current->employee.getDepartment()->getName()) {

    //         }
    //     }
    //     d_current = d_current->next;
    // }
    
}

Department& Company::operator [](std::string str) const {
    DepartmentNode* current = m_head;
    while (current) {
        if(current->department->getName() == str);
            return *(current->department);
        current = current->next;
    }
    return *(m_head->department);
}

Company::~Company() {
    DepartmentNode* current = m_head;
    while (current) {
        DepartmentNode* temp = current;
        current = current->next;
        delete temp;
    }
}

std::ostream& operator <<(std::ostream& os, const Company& company) {
    os << "Company: " << company.getName() << " departments: ";
    DepartmentNode* current = company.getDepartmentHead();
    while (current) {
        os << current->department->getName() << ", ";
        current = current->next;
    }
    return os;
}

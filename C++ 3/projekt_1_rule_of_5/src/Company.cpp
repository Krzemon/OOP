#include "Company.h"
#include "Department.h"

Company::Company(std::string name) : m_name(name), m_head(nullptr), m_tail(nullptr) {}

// 🔹 Destruktor - zwalnia dynamiczną pamięć
Company::~Company() {
    DepartmentNode* current = m_head;
    while (current) {
        DepartmentNode* temp = current;
        current = current->next;
        delete temp;
    }
}

// 🔹 Konstruktor kopiujący
Company::Company(const Company& other) : m_name(other.m_name), m_head(nullptr), m_tail(nullptr) {
    DepartmentNode* current = other.m_head;
    while (current) {
        addDepartment(*current->department);
        current = current->next;
    }
}

// 🔹 Operator przypisania kopiujący
Company& Company::operator=(const Company& other) {
    if (this != &other) {
        while (m_head) {
            DepartmentNode* temp = m_head;
            m_head = m_head->next;
            delete temp;
        }

        m_name = other.m_name;
        m_head = m_tail = nullptr;
        DepartmentNode* current = other.m_head;
        while (current) {
            addDepartment(*current->department);
            current = current->next;
        }
    }
    return *this;
}

// 🔹 Konstruktor przenoszący
Company::Company(Company&& other) noexcept 
    : m_name(std::move(other.m_name)), m_head(other.m_head), m_tail(other.m_tail) {
    other.m_head = nullptr;
    other.m_tail = nullptr;
}

// 🔹 Operator przypisania przenoszącego
Company& Company::operator=(Company&& other) noexcept {
    if (this != &other) {
        std::swap(m_name, other.m_name);
        std::swap(m_head, other.m_head);
        std::swap(m_tail, other.m_tail);
    }
    return *this;
}

// 🔹 Dodanie działu do firmy (lista dwukierunkowa)
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

// 🔹 Wypisanie wszystkich działów w firmie
void Company::printDepartments() const {
    std::cout << "Company: " << m_name << " departments:" << std::endl;
    DepartmentNode* current = m_head;
    while (current) {
        std::cout << "- " << current->department->getName() << std::endl;
        current = current->next;
    }
}

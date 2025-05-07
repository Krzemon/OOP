#include "Department.h"

Department::Department(const std::string& name) : m_name(name), m_head(nullptr), m_tail(nullptr) {}

Department::~Department() {
    while (m_head) {
        EmployeeNode* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}

// Kopiowanie
Department::Department(const Department& other) : m_name(other.m_name), m_head(nullptr), m_tail(nullptr) {
    EmployeeNode* current = other.m_head;
    while (current) {
        addEmployee(*current->employee);
        current = current->next;
    }
}

// Operator przypisania kopiujący
Department& Department::operator=(const Department& other) {
    if (this != &other) {
        while (m_head) {
            removeEmployee(m_head->employee->printInfo());
        }
        m_name = other.m_name;
        EmployeeNode* current = other.m_head;
        while (current) {
            addEmployee(*current->employee);
            current = current->next;
        }
    }
    return *this;
}

// Konstruktor przenoszący
Department::Department(Department&& other) noexcept 
    : m_name(std::move(other.m_name)), m_head(other.m_head), m_tail(other.m_tail) {
    other.m_head = nullptr;
    other.m_tail = nullptr;
}

// Operator przypisania przenoszący
Department& Department::operator=(Department&& other) noexcept {
    if (this != &other) {
        std::swap(m_name, other.m_name);
        std::swap(m_head, other.m_head);
        std::swap(m_tail, other.m_tail);
    }
    return *this;
}

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

void Department::removeEmployee(const std::string& name) {
    EmployeeNode* current = m_head;
    while (current) {
        if (current->employee->printInfo() == name) {
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

Employee& Department::operator[](int index) {
    EmployeeNode* current = m_head;
    int count = 0;
    while (current) {
        if (count == index) return *(current->employee);
        current = current->next;
        count++;
    }
    throw std::out_of_range("Index out of bounds");
}

std::string Department::getName() const {
    return m_name;
}

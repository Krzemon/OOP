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
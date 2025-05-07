#include "University.h"
#include "ScienceDepartment.h" // operator=(University&&)

University::University() {
    std::cout << "[INFO]:: University created." << std::endl;
}

University& University::operator=(University&& other) noexcept {
    if (this != &other) {
        std::cout << "[INFO]:: University move assignment.\n";
        departments_.clear();
        departments_ = std::move(other.departments_);
        other.departments_.clear();
    }
    return *this;
}

University::University(University&& other) noexcept {
    std::cout << "[INFO]:: University move constructor.\n";
    departments_ = std::move(other.departments_);
    other.departments_.clear();
}

University::~University() {
    std::cout << "[INFO]:: University destroyed." << std::endl;
}

void University::add(std::unique_ptr<Department> department) {
    departments_.push_back(std::move(department));
}

std::unique_ptr<Department> University::pop_back_department() {
    if (departments_.empty()) {
        return nullptr;
    }
    auto department = std::move(departments_.back());
    departments_.pop_back();
    return department;
}

void University::info() const {

    if (departments_.empty()) {
        std::cout << "[INFO]:: No departments assigned." << std::endl;
    } else {
        std::cout << "[INFO]:: University departments:\n";
        for (const auto& dept : departments_) {
            std::cout << "      ";
            dept->info();
        }
    }
}
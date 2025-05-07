#include "University.h"

University::University() {
    std::cout << "University created.\n";
}

University::~University() {
    std::cout << "University destroyed.\n";
}

University::University(University&& other) noexcept
    : departments_(std::move(other.departments_)) {
    std::cout << "University move constructor.\n";
}

University& University::operator=(University&& other) noexcept {
    if (this != &other) {
        departments_ = std::move(other.departments_);
        std::cout << "University move assignment.\n";
    }
    return *this;
}

void University::add(std::unique_ptr<Department> dep) {
    departments_.push_back(std::move(dep));
    std::cout << "Department added to University.\n";
}

void University::info() const {
    if (departments_.empty()) {
        std::cout << "No departments assigned.\n";
    } else {
        for (const auto& dep : departments_) {
            dep->info();
        }
    }
}

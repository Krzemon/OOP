#include "University.h"

University::University() {
    std::cout << "[INFO]:: University created." << std::endl;
}

University::~University() {
    std::cout << "[INFO]:: University destroyed." << std::endl;
}

University::University(University&& other) noexcept
    : departments_(std::move(other.departments_)) {
    std::cout << "[INFO]:: University move assignment." << std::endl;
}

University& University::operator=(University&& other) noexcept {
    if (this != &other) {
        departments_ = std::move(other.departments_);
        std::cout << "[INFO]:: University move assignment." << std::endl;
    }
    return *this;
}

void University::add(std::unique_ptr<Department> department) {
    departments_.emplace_back(std::move(department));
}

void University::info() const {
    if (departments_.empty()) {
        std::cout << "[INFO]:: No departments assigned." << std::endl;
    } else {
        std::cout << "[INFO]:: University departments:" << std::endl;
        for (size_t i = 0; i < departments_.size(); ++i) {
            std::cout << "\t[" << i << "] ";
            departments_[i]->info();
        }
    }
}

std::unique_ptr<Department> University::pop_back_department() {
    if (departments_.empty())
        return nullptr;
    auto last = std::move(departments_.back());
    departments_.pop_back();
    return last;
}

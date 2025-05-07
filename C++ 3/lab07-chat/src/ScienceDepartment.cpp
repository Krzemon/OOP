#include "ScienceDepartment.h"
#include <iostream>

ScienceDepartment::ScienceDepartment(const std::string& name)
    : Department(name) {}

ScienceDepartment::ScienceDepartment(std::string&& name)
    : Department(std::move(name)) {}

void ScienceDepartment::add_divisions(const std::vector<std::string>& divisions) {
    divisions_ = divisions;
}

void ScienceDepartment::info() const {
    std::cout << "[Science]: '" << name_ << "' [divisions]: ";
    if (divisions_.empty()) {
        std::cout << "None";
    } else {
        for (const auto& division : divisions_) {
            std::cout << division << " ";
        }
    }
    std::cout << std::endl;
}

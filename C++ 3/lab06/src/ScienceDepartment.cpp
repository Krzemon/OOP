#include "ScienceDepartment.h"

ScienceDepartment::ScienceDepartment() {
    std::cout << "ScienceDepartment created.\n";
}

ScienceDepartment::~ScienceDepartment() {
    std::cout << "ScienceDepartment destroyed.\n";
}

void ScienceDepartment::info() const {
    std::cout << "Science Department (Physics, Chemistry, Biology)\n";
}

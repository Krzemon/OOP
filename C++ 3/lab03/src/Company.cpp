#include "Company.h"
#include <iostream>

Company::Company(const std::string& companyName, int maxDepts) 
    : name(companyName), maxDepartments(maxDepts), currentDepartments(0) {
    departments = new Department[maxDepts];
}

Company::~Company() {
    delete[] departments;
}

void Company::addDepartment(const Department& dept) {
    if (currentDepartments < maxDepartments) {
        departments[currentDepartments++] = dept;
    }
}

void Company::printDepartments() const {
    std::cout << "Company: " << name << " departments:\n";
    for (int i = 0; i < currentDepartments; i++) {
        std::cout << "- " << departments[i].getName() << "\n";
    }
}

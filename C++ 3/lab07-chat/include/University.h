#pragma once
#include "Department.h"
#include <vector>
#include <memory>
#include <iostream>

class University {
public:
    University();
    ~University();

    // Move constructor
    University(University&& other) noexcept;
    // Move assignment
    University& operator=(University&& other) noexcept;

    void add(std::unique_ptr<Department> department);
    void info() const;
    std::unique_ptr<Department> pop_back_department();

private:
    std::vector<std::unique_ptr<Department>> departments_;
};

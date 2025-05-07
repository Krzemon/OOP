#pragma once
#include "Department.h"

class ScienceDepartment final : public Department {
public:
    ScienceDepartment(const std::string& name);
    ScienceDepartment(std::string&& name);

    void add_divisions(const std::vector<std::string>& divisions);
    void info() const override;

private:
    std::vector<std::string> divisions_;
};

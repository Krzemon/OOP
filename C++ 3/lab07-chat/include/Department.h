#pragma once
#include <string>
#include <vector>
#include <iostream>

class Department {
public:
    Department(const std::string& name) : name_(name) {}
    Department(std::string&& name) : name_(std::move(name)) {}
    virtual ~Department() = default;

    virtual void info() const = 0; // czysta metoda wirtualna

    // Metody pomocnicze
    const std::string& name() const { return name_; }

protected:
    std::string name_;
};


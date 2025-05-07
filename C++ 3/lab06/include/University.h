#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Department.h"
#include <memory>
#include <vector>

class Department;

class University: public Department {
private:
    std::vector<std::unique_ptr<Department>> departments_;

public:
    /**
     * @brief konstruktor
     */ 
    University();
    /**
     * @brief destruktor
     */ 
    ~University();

    University(const University&) = delete;
    University& operator=(const University&) = delete;

    University(University&& other) noexcept;
    University& operator=(University&& other) noexcept;
    
    /**
     * @brief metoda wypisujaca informacje
     */ 
    void info() const;

    /**
     * @brief metoda dodajaca
     */ 
    void add(std::unique_ptr<Department> dept);
};

#endif // UNIVERSITY_H

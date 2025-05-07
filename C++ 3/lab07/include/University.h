#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Department.h"
#include <memory>
#include <vector>
#include <iostream>

class University {
private:
    std::vector<std::unique_ptr<Department>> departments_;

public:

    University();
    virtual ~University();
    /**
     * @brief konstruktor kopiujacy
     */
    University(const University&) = default;
    /**
     * @brief operator kopiujacy
     */
    University& operator=(const University& other) = default;
    /**
     * @brief konstruktor przenoszacy
     */
    University(University&&) noexcept;
    /**
     * @brief operator przenoszacy
     */
    University& operator=(University&&) noexcept;

    /**
     * @brief dodaje unique_ptr do wektora departments_
     */
    void add(std::unique_ptr<Department> department);
    /**
     * @brief dodaje usuwa z konca listy deparament
     */
    std::unique_ptr<Department> pop_back_department();
    /**
     * @brief wyswietla informacje o klasie University
     */
    void info() const;
};

#endif // UNIVERSITY_H

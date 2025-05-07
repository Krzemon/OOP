#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include <iostream>

class Department {
public:
    Department() = default;
    virtual ~Department() = default;
    /**
     * @brief konstruktor kopiujacy
     */
    Department(const Department&) = default;
    /**
     * @brief operator kopiujacy
     */
    Department& operator=(const Department&) = default;
    /**
     * @brief konstruktor przenoszacy
     */
    Department(Department&&) = default;
    /**
     * @brief operator przenoszacy
     */
    Department& operator=(Department&&) = default;
    /**
     * @brief wyswietla informacje o klasie Department
     */
    virtual void info() const = 0;
};

#endif // DEPARTMENT_H
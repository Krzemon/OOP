#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>

class Department {
public:
    /**
     * @brief konstruktor
     */ 
    Department();
    /**
     * @brief destruktor
     */ 
    virtual ~Department();
    /**
     * @brief konstruktor przenoszacy
     */ 
    Department(const Department&) = delete;
    /**
     * @brief operator przenoszacy
     */ 
    Department& operator=(const Department&) = delete;
    /**
     * @brief konstruktor przenoszacy
     */ 
    Department(Department&&) noexcept = default;
    /**
     * @brief operator przenoszacy
     */ 
    Department& operator=(Department&&) noexcept = default;
    /**
     * @brief metoda wypisujaca informacje 
     */
    virtual void info() const = 0;
};


#endif // DEPARTMENT_H
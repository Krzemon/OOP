#ifndef SCIENCEDEPARTMENT_H
#define SCIENCEDEPARTMENT_H

#include "Department.h"

class ScienceDepartment : public Department {
public:
    /**
     * @brief konstruktor
     */ 
    ScienceDepartment();
    /**
     * @brief destruktor
     */ 
    ~ScienceDepartment() override;

    ScienceDepartment(const ScienceDepartment&) = delete;
    ScienceDepartment& operator=(const ScienceDepartment&) = delete;

    ScienceDepartment(ScienceDepartment&&) noexcept = default;
    ScienceDepartment& operator=(ScienceDepartment&&) noexcept = default;
    /**
     * @brief metoda wypisujaca informacje
     */ 
    void info() const override;
};

#endif // SCIENCEDEPARTMENT_H
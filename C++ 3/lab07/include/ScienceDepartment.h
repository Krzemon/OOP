#ifndef SCIENCE_DEPARTMENT_H
#define SCIENCE_DEPARTMENT_H

#include "Department.h"
#include <string>
#include <vector>

class ScienceDepartment : public Department {
private:
    std::string name_;
    std::vector<std::string> divisions_;
    static int num;
public:

    ScienceDepartment(const std::string& name) : name_(name) {}
    /**
     * @brief dodaje podzial 
     */
    void add_divisions(const std::vector<std::string>& divisions);
    /**
     * @brief wyswietla informacje o klasie University
     */
    void info() const override;
    /**
     * @brief zeruje licznik
     */
    static void set_num() {num = 0;}
};

#endif // SCIENCE_DEPARTMENT_H
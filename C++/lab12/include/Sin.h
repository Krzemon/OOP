#ifndef SIN_H
#define SIN_H

#include "Function.h"
#include <cmath>

class Sin : public Function {
public:
    Sin(double a) : a(a) {}
    double operator ()(const double& x) const override {
        return sin(a*x);
    }
    void set_parameter(double a) {
        this->a = a;
    }
    ~Sin() {std::cout << "Sin destructor" << std::endl;}
private:
    double a;
};

#endif // SIN_H
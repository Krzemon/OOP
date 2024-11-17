#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "Function.h"

class Quadratic : public Function {
public:
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}
    double operator ()(const double& x) const override {
        return a*x*x + b*x + c;
    }
    void set_abc(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    ~Quadratic() {std::cout << "Quadratic destructor" << std::endl;}
private:
    double a, b, c;
};

#endif // QUADRATIC_H
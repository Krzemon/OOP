#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

class Function {
public:
    virtual double operator ()(const double& x) const = 0;
    double calc(const double& x) const {
        return (*this)(x);
    }
    virtual ~Function() {std::cout << "Function destructor" << std::endl;}
};

#endif // FUNCTION_H
#ifndef FUNCTION_H
#define FUNCTION_H

#include <cmath>
#include <iostream>

class Function {
public:
    virtual double calc(double x) = 0;
    virtual ~Function() {
        std::cout << "Function destructor" << std::endl;
    }
};

#endif // FUNCTION_H
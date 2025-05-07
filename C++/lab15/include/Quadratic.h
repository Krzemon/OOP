#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "Function.h"

class Quadratic: public Function {
private:
private:
    double a;
    double b;
    double c;
public:
    /**
     * @brief Construct a new Quadratic object
     */
    Quadratic(double a, double b, double c);
    /**
     * @brief Calculate the quadratic function
     */
    double calc(double x);

};

#endif // QUADRATIC_H
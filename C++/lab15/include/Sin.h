#ifndef SIN_H
#define SIN_H

#include "Function.h"

class Sin : public Function {
private:
    double parameter;
public:
    /**
     * @brief Construct a new Sin object
     */
    Sin(double parameter);
    /**
     * @brief Set the parameter object
     */
    void set_parameter(double parameter);
    /**
     * @brief Calculate the sin function
     */
    double calc(double x);
};

#endif // SIN
#include "Quadratic.h"

Quadratic::Quadratic(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double Quadratic::calc(double x) {
    return a * x * x + b * x + c;
}


#include "Sin.h"

Sin::Sin(double parameter) {
    this->parameter = parameter;
}

void Sin::set_parameter(double parameter) {
    this->parameter = parameter;
}

double Sin::calc(double x) {
    return sin(parameter * x);
}

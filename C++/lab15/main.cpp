#include "iostream"
#include "Quadratic.h"
#include "Sin.h"

int main() {
    Sin sinus(4.); // sin(4*x)
    std::cout << "sin: " << sinus.calc(0.5) << std::endl;
    sinus.set_parameter(2);
    std::cout << "sin: " << sinus.calc(0.5) << std::endl;

    Function *quadratic_fun = new Quadratic(4, 6, 2);
    std::cout << "quadratic: " << quadratic_fun->calc(1.5) << std::endl;
    delete quadratic_fun;
    
    return 0;
}
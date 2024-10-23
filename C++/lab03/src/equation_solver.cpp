#include "equation_solver.h"

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return !iss.fail() && iss.eof();
}

void handleOneArgument(float a) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int b = std::rand() % static_cast<int>(a);
    
    std::cout << "Do programu podano liczbę " << a << ". Wylosowano liczbę " << b << ". Wszystkie liczby nieparzyste naturalne mniejsze lub równe " << a << ":" << std::endl;
    
    for (int i = 1; i <= static_cast<int>(a); i++) {
        if (i % 2 == 1) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

void handleTwoArguments(float a, float b) {
    if (!(std::abs(a) < 1e-7)) {
        if (std::abs(b) < 1e-7)
            std::cout << "Do programu podano funkcję f(x) = " << a << "*x. Rozwiązaniem równania f(x) = 0 jest x = 0" << std::endl;
        else
            std::cout << "Do programu podano funkcję f(x) = " << a << "*x + " << b << ". Rozwiązaniem równania f(x) = 0 jest x = " << -b / a << std::endl;
    } else {
        std::cout << "Do programu podano funkcję f(x) = " << b << std::endl;
        std::cout << "Funkcja jest stała, nie ma rozwiązania równania f(x) = 0." << std::endl;
    }
}

void handleThreeArguments(float a, float b, float c) {
    if ((std::abs(a) < 1e-7)) {
        if (std::abs(b) < 1e-7) {
            if (std::abs(c) < 1e-7)
                std::cout << "Do programu podano funkcję f(x) = " << c << ". Rozwiązaniem równania f(x) = 0 jest każde x należące do dziedziny." << std::endl;
            else
                std::cout << "Do programu podano funkcję f(x) = " << c << ". Funkcja jest stała, nie ma rozwiązania równania f(x) = 0." << std::endl;
        } else {
            std::cout << "Do programu podano funkcję f(x) = " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 jest x = " << -c / b << std::endl;
        }
    } else {
        float delta = b * b - 4 * a * c;
        if (delta > 0) {
            std::cout << "Do programu podano funkcję f(x) = " << a << "*x^2 + " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 są x1 = " 
                      << (-b + std::sqrt(delta)) / (2 * a) << " oraz x2 = " 
                      << (-b - std::sqrt(delta)) / (2 * a) << std::endl;
        } else if (std::abs(delta) < 1e-7) {
            std::cout << "Do programu podano funkcję f(x) = " << a << "*x^2 + " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 jest x = " 
                      << -b / (2 * a) << std::endl;
        } else {
            std::complex<float> x1, x2;
            x1 = (-std::complex<float>(b) + std::sqrt(std::complex<float>(delta))) / (2 * a);
            x2 = (-std::complex<float>(b) - std::sqrt(std::complex<float>(delta))) / (2 * a);
            std::cout << "Do programu podano funkcję f(x) = " << a << "*x^2 + " << b << "*x + " << c << ". Rozwiązaniem równania f(x) = 0 są x1 = " 
                      << x1 << " oraz x2 = " << x2 << std::endl;
        }
    }
}

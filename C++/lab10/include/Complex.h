#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // konstruktory
    Complex();
    Complex(double real, double imag);

    // Przeciążony operator mniejszości
    bool operator<(const Complex& other) const;

    // zaprzyjaźniony operator << do wypisywania liczb zespolonych
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

bool Complex::operator<(const Complex& other) const {
    return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * other.real + other.imag * other.imag);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << "+";
    os << c.imag << "i";
    return os;
}

#endif

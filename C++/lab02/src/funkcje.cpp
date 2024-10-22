#include <iostream>
#include "funkcje.h"

// Funkcja sprawdzająca, czy rok jest przestępny
bool przestepny(int rok) {
    if (rok % 4 == 0) {
        if (rok % 100 == 0) {
            return (rok % 400 == 0);
        }
        return true;
    }
    return false;
}

// Funkcja wypisująca parzyste liczby z przedziału
void parzyste_z_przedzialu(int a, int b) {
    std::cout << "Parzyste liczby z przedziału [" << a << ", " << b << "]: ";
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0)
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Funkcja zwracająca największą z trzech liczb
int max_z_lisc(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}
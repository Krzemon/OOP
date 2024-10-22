#include <iostream>
#include <iomanip>
#include "sierpinski.h"
#include "pascal.h" // Potrzebne do korzystania z funkcji wartosc

#define maxFieldWidth 1

// Funkcja sprawdzająca, czy liczba jest parzysta
bool isEven(int number) {
    return number % 2 == 0;
}

// Funkcja wypisująca trójkąt Sierpińskiego na podstawie trójkąta Pascala
void sierpinski(int n) {
    int fieldWidth = 2 * maxFieldWidth;
    for (int i = 0; i < n; i++) {
        int spacesBefore = (n - i - 1) * maxFieldWidth;
        std::cout << std::setw(spacesBefore) << "";

        for (int j = 0; j <= i; ++j) {
            int value = wartosc(i, j);
            if (isEven(value)) {
                std::cout << std::setw(fieldWidth) << std::right << ".";
            } else {
                std::cout << std::setw(fieldWidth) << std::right << " ";
            }
        }

        std::cout << std::endl;
    }
}

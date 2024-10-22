#include <iostream>
#include <iomanip>
#include "pascal.h"

// Funkcja obliczająca wartość w danym miejscu trójkąta Pascala
int wartosc(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return wartosc(n - 1, k - 1) + wartosc(n - 1, k);
}

// Funkcja wypisująca n wierszy trójkąta Pascala
void pascal(int n) {
    int maxWidth = 0;

    // Najpierw znajdź maksymalną szerokość dla ostatniego wiersza
    for (int j = 0; j <= n - 1; ++j) {
        int value = wartosc(n - 1, j);
        int width = std::to_string(value).length(); // Długość liczby jako string
        if (width > maxWidth) {
            maxWidth = width;
        }
    }
    maxWidth += 2;

    // wypisz trójkąt Pascala
    for (int i = 0; i < n; i++) {
        int spacesBefore = (n - i - 1) * (maxWidth / 2);
        std::cout << std::setw(spacesBefore) << ""; // Dodaj spacje przed wierszem

        for (int j = 0; j <= i; ++j) {
            int value = wartosc(i, j);
            std::cout << std::setw(maxWidth) << std::right << value;
        }

        std::cout << std::endl;
    }
}

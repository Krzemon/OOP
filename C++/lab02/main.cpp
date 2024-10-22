#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include <ctime>
#include <iomanip>
#include "funkcje.h"

int main(int argc, char const *argv[]) {
    // zad 1
    unsigned int rok;
    std::cout << "Podaj rok: ";
    std::cin >> rok;
    przestepny(rok) ? std::cout << "Rok " << rok << " jest przestepny\n" : std::cout << "Rok " << rok << " nie jest przestepny\n";

    // zad 2
    int a, b;
    std::cout << "Podaj a: ";
    std::cin >> a;
    std::cout << "Podaj b: ";
    std::cin >> b;
    parzyste_z_przedzialu(a, b);

    // zad 3
    int x, y, z;
    std::cout << "Podaj trzy liczby: ";
    std::cin >> x >> y >> z;
    std::cout << "Największa liczba to: " << max_z_lisc(x, y, z) << std::endl;

    // zad 4
    std::srand(std::time(nullptr));
    switch (argc) {
        case 3:
            double dolar;
            dolar = std::atof(argv[1]) * std::atof(argv[2]);
            std::cout << "Zamienione PLN na USD: " << dolar << std::endl; 
            break;
        case 2:
            double farenheit;
            farenheit = (std::atof(argv[1]) * 1.8) + 32;
            std::cout << "Zamienione stopnie na farenheity: " << farenheit << std::endl; 
            break;
        case 4:
            int wybor;
            do {
                std::cout << "Podałeś stopnie (1), czy radiany (2)?: ";
                std::cin >> wybor;
                if (wybor == 1)
                    std::cout << std::sin((std::atof(argv[1]) + std::atof(argv[2]) + std::atof(argv[3])) / 3 * M_PI / 180.0) << std::endl;
                else if (wybor == 2)
                    std::cout << std::sin((std::atof(argv[1]) + std::atof(argv[2]) + std::atof(argv[3])) / 3) << std::endl;
            } while (wybor != 1 && wybor != 2);
            break;
        case 1:
            double randomNumber = static_cast<double>(std::rand()) / RAND_MAX;
            std::cout << "Wygenerowana liczba pseudolosowa: " << randomNumber << std::endl;
            break;
    }

    // zad 5
    double tab[10];
    for (size_t i = 0; i < 10; ++i) {
        tab[i] = std::sin(i);
        std::cout << "sin(" << i << ") = " << tab[i] << std::endl;
    }

    // zad 6
    size_t count = 10;
    int** dynamicTab = new int*[count];

    for (size_t i = 0; i < count; ++i) {
        dynamicTab[i] = new int[count];
        for (size_t j = 0; j < count; ++j) {
            dynamicTab[i][j] = static_cast<int>(i * j);
            std::cout << std::setw(4) << dynamicTab[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (size_t i = 0; i < count; ++i) {
        delete[] dynamicTab[i];
    }
    delete[] dynamicTab;

    return 0;
}
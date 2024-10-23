#include "rownanie_kwadratowe.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    double a = 2, b = 1, c = 1;

    switch (argc) {
        case 1:
            break;
        case 4:
            if (!isNumber(argv[1]) || !isNumber(argv[2]) || !isNumber(argv[3])) {
                std::cout << "Argumenty nie są liczbami.\n";
                return 1;
            } else {
                a = std::atof(argv[1]);
                b = std::atof(argv[2]);
                c = std::atof(argv[3]);
            }
            break;
        default:
            std::cout << "Podaj trzy argumenty.\n";
            return 1;
    }

    WynikRownaniaKwadratowego* wynik = rownanieKwadratowe(a, b, c);
    wypiszWynik(wynik);

    std::cout << "Czy liczba z1 jest rzeczywista? " << jestRzeczywista(&(wynik->x1)) << std::endl;
    std::cout << "Czy liczba z1 jest urojona?     " << jestUrojona(&(wynik->x1)) << std::endl;
    std::cout << "Czy liczba z2 jest rzeczywista? " << jestRzeczywista(&(wynik->x2)) << std::endl;
    std::cout << "Czy liczba z2 jest urojona?     " << jestUrojona(&(wynik->x2)) << std::endl;

    delete wynik;
    return 0;
}

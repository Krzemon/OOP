#ifndef ROWNANIE_KWADRATOWE_H
#define ROWNANIE_KWADRATOWE_H

#include <string>

struct Zespolona {
    double re;
    double im;
};

struct WynikRownaniaKwadratowego {
    Zespolona x1;
    Zespolona x2;
};

// Funkcja obliczająca pierwiastki równania kwadratowego
WynikRownaniaKwadratowego* rownanieKwadratowe(const double& a, const double& b, const double& c);

// Funkcja wypisująca wynik równania kwadratowego
void wypiszWynik(WynikRownaniaKwadratowego* wynik);

// Funkcja wypisująca liczbę zespoloną
bool isNumber(const std::string& str);

// Funkcja wypisująca liczbę zespoloną
bool jestUrojona(Zespolona* num);

// Funkcja wypisująca liczbę zespoloną
bool jestRzeczywista(Zespolona* num);

#endif // ROWNANIE_KWADRATOWE_H

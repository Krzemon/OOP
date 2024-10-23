#include "rownanie_kwadratowe.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

WynikRownaniaKwadratowego* rownanieKwadratowe(const double& a, const double& b, const double& c) {
    WynikRownaniaKwadratowego* wynik = new WynikRownaniaKwadratowego;
    double delta = b*b - 4*a*c;

    if (delta >= 0) {
        wynik->x1.re = (-b + sqrt(delta)) / (2*a);
        wynik->x1.im = 0;
        wynik->x2.re = (-b - sqrt(delta)) / (2*a);
        wynik->x2.im = 0;
    } else {
        wynik->x1.re = (-b) / (2*a);
        wynik->x1.im = sqrt(-delta) / (2*a);
        wynik->x2.re = (-b) / (2*a);
        wynik->x2.im = -sqrt(-delta) / (2*a);
    }

    return wynik;
}

void wypiszWynik(WynikRownaniaKwadratowego* wynik) {
    std::cout << "Re{z_1} = " << wynik->x1.re << "  " << "Im{z_1} = " << wynik->x1.im << std::endl;
    std::cout << "Re{z_2} = " << wynik->x2.re << "  " << "Im{z_2} = " << wynik->x2.im << std::endl;
}

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return !iss.fail() && iss.eof();
}

bool jestUrojona(Zespolona* num) {
    return num->im != 0;
}

bool jestRzeczywista(Zespolona* num) {
    return num->im == 0;
}

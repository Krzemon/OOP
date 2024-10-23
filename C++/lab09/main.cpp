#include <iostream>
#include "Osoba.h"
#include "Pracownik.h"

enum stanowisko {zwykly, kierownik, prezes};

int main() {
    int placa[] = {1600, 2100, 8900};

    Pracownik jasio("Jasio", 1978, placa[zwykly]);
    Pracownik henio("Henio", 1980, placa[zwykly]);
    Pracownik jan("Jan", 1965, placa[kierownik]);
    Pracownik panJan("Pan Jan", 1955, placa[prezes]);

    jasio.info();
    henio.info();
    jan.info();
    panJan.info();

    std::cout << "\nZmieniamy place\n\n";

    placa[zwykly] -= 300;
    placa[prezes] += 1000;
    jasio.info();
    henio.info();
    jan.info();
    panJan.info();

    std::cout << "\nKoniec programu\n\n";
    return 0;
}

#include "Osoba.h"

Osoba::Osoba(const char* imie_nazwisko, int rok_urodzenia)
    : imie_nazwisko(imie_nazwisko), rok_urodzenia(rok_urodzenia) {
    std::cout << "Tworzymy osobe " << imie_nazwisko << "\n";
}

Osoba::~Osoba() {
    std::cout << "Usuwamy osobe " << imie_nazwisko << "\n";
}

const char* Osoba::getImieNazwisko() const {
    return imie_nazwisko;
}

int Osoba::getRokUrodzenia() const {
    return rok_urodzenia;
}

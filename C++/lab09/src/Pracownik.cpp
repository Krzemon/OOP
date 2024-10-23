#include "Pracownik.h"

int Pracownik::unikalnyNumerId = 0;

Pracownik::Pracownik(const char* imie_nazwisko, int rok_urodzenia, int zarobki)
    : id(++unikalnyNumerId), osoba(imie_nazwisko, rok_urodzenia), zarobki(zarobki) {}

void Pracownik::info() const {
    std::cout << osoba.getImieNazwisko() << " (r.ur. " << osoba.getRokUrodzenia()
              << ") id=" << id << "; zarobki: " << zarobki << std::endl;
}
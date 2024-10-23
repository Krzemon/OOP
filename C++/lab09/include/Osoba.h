#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>
#include <string>

class Osoba {
private:
    const char* imie_nazwisko;
    int rok_urodzenia;

public:
    // konstruktor
    Osoba(const char* imie_nazwisko, int rok_urodzenia);
    // destruktor
    ~Osoba();
    // gettery
    const char* getImieNazwisko() const;
    int getRokUrodzenia() const;
};

#endif
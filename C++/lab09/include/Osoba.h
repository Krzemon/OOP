#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>
#include <string>

class Osoba {
private:
    const char* imie_nazwisko;
    int rok_urodzenia;

public:
    Osoba(const char* imie_nazwisko, int rok_urodzenia);
    ~Osoba();
    const char* getImieNazwisko() const;
    int getRokUrodzenia() const;
};

#endif
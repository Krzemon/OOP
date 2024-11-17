#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "Osoba.h"

class Pracownik {
private:
    static int unikalnyNumerId;
    const int id;
    const Osoba osoba;
    int zarobki;

public:
    Pracownik(const char* imie_nazwisko, int rok_urodzenia, int zarobki);
    void info() const;
};

#endif
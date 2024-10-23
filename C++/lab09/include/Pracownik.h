#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "Osoba.h"

class Pracownik {
private:
    static int unikalnyNumerId;  // statyczne pole przechowujące unikalny numer ID
    const int id;                // unikalny numer ID
    const Osoba osoba;           // instancja klasy Osoba
    int zarobki;                 // zarobki pracownika

public:
    // konstruktor
    Pracownik(const char* imie_nazwisko, int rok_urodzenia, int zarobki);
    // metoda zwracająca zarobki pracownika
    void info() const;
};

#endif
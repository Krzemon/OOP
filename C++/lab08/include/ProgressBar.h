#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <iostream>

class ProgressBar {
private:
    int total;      // Liczba, która reprezentuje 100% postępu
    int length;     // Długosć paska postępu (domyślnie 50)
    char symbol;    // Znak, który reprezentuje postęp

public:
    // Konstruktor 
    ProgressBar(int total, int length = 50, char symbol = '>');
    // Metoda odświeżająca pasek postępu
    void refresh(int progress); 
    // Metoda zmieniająca symbol paska postępu
    void setSymbol(char newSymbol);
    // Metoda zmieniająca długość paska postępu
    void setLength(int newLength);
};

#endif
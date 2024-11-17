#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

class Histogram {
private:
    int n;          // Liczba zmiennych losowych
    int nEntries;   // Liczba próbek
    int nBins;      // Liczba przedziałów
    double xMin;    // Minimalna wartość zmiennej losowej
    double xMax;    // Maksymalna wartość zmiennej losowej
    int height;     // Wysokość histogramu
    const char* sign; // Znak reprezentujący histogram

public:
    Histogram(int n = 2, int nEntries = 1000, int nBins = 50, double xMin = 0, double xMax = 1, int height = 30, const char* sign = "|");
    Histogram(int argc, char* argv[], int n = 2, int nEntries = 1000, int nBins = 50, double xMin = 0, double xMax = 1, int height = 30, const char* sign = "|");

    // Metoda generująca histogram
    void generate();

    // Metoda wypisująca histogram
    void print();

    // Metoda zwracająca wartość zmiennej losowej
    double getValue(int i);

    // Metoda zwracająca liczbę przedziałów
    int getNBins();

    // Metoda zwracająca liczbę próbek
    int getNEntries();
    
    void setNEntries(int nEntries) { this->nEntries = nEntries; }
    void setNBins(int nBins) { this->nBins = nBins; }
    void setXMin(double xMin) { this->xMin = xMin; }
    void setXMax(double xMax) { this->xMax = xMax; }
    void setHeight(int height) { this->height = height; }
    void setSign(const char* sign) { this->sign = sign; }
    void setN(int n) { this->n = n; }
    
};

#endif // HISTOGRAM_H
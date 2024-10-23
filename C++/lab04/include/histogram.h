#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <string>

// Funkcja sprawdzająca czy podany string jest liczbą 
bool isNumber(const std::string& str);

// Funkcja sprawdzająca czy podany string jest liczbą całkowitą
void switches(char& tekstura, int& liczba_binow, int& wysokosc, float& x_min, float& x_max, int& N, int argc, char* argv[]);

// Funkcja generująca histogram
void histogram(const char& tekstura, const int& liczba_binow, const int& wysokosc, const float& x_min, const float& x_max, const int& N);

#endif // HISTOGRAM_H
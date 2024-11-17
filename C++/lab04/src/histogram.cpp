#include "histogram.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return !iss.fail() && iss.eof();
}

void switches(char& tekstura, int& liczba_binow, int& wysokosc, float& x_min, float& x_max, int& N, int argc, char* argv[]){
    std::string argument = argv[1];
    switch (argc - 1) {
        case 6:
            if (!isNumber(argv[6])) {
                std::cout << "Argument representing N is not a number.\n";
                exit(1);
            }
            N = std::atoi(argv[6]);
            // Fallthrough
        case 5:
            if (!isNumber(argv[5])) {
                std::cout << "Argument representing x_max is not a number.\n";
                exit(1);
            }
            x_max = std::atof(argv[5]);
            // Fallthrough
        case 4:
            if (!isNumber(argv[4])) {
                std::cout << "Argument representing x_min is not a number.\n";
                exit(1);
            }
            x_min = std::atof(argv[4]);
            // Fallthrough
        case 3:
            if (!isNumber(argv[3])) {
                std::cout << "Argument representing height is not a number.\n";
                exit(1);
            }
            wysokosc = std::atoi(argv[3]);
            // Fallthrough
        case 2:
            if (!isNumber(argv[2])) {
                std::cout << "Argument representing the number of bins is not a number.\n";
                exit(1);
            }
            liczba_binow = std::atoi(argv[2]);
            // Fallthrough
        case 1:
            tekstura = argument[0];
            break;
        default:
            std::cout << "Too many arguments provided.\n";
            exit(1);
    }
}

void histogram(const char& tekstura, const int& liczba_binow, const int& wysokosc, const float& x_min, const float& x_max, const int& N) {
    srand(static_cast<unsigned>(time(nullptr)));
    
    float* tab = new float[1000]{ 0 };
    float* data = new float[liczba_binow]{ 0 };
    float h_max = 0, suma = 0, suma_kwadratow = 0;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < N; ++j)
            tab[i] += static_cast<float>(rand()) / (RAND_MAX + 1.0f);
        tab[i] /= N;
        suma += tab[i];
        suma_kwadratow += tab[i] * tab[i];

        int bin_index = static_cast<int>((tab[i] - x_min) / (x_max - x_min) * liczba_binow);
        if (bin_index >= 0 && bin_index < liczba_binow)
            data[bin_index]++;
    }
    delete[] tab;

    float srednia = suma / 1000;
    float wariancja = (suma_kwadratow - (suma * suma) / 1000) / (1000 - 1);
    float odchylenie = std::sqrt(wariancja);

    for (int i = 0; i < liczba_binow; ++i)
        if (data[i] > h_max)
            h_max = data[i];

    float delta = h_max / (wysokosc + 1);

    for (int i = 0; i < liczba_binow; ++i) std::cout << "-";
    std::cout << std::endl;

    for (int i = wysokosc; i >= 0; --i) {
        for (int j = 0; j < liczba_binow; ++j) {
            if (data[j] > delta * i)
                std::cout << tekstura;
            else
                std::cout << ' ';
        }
        std::cout << "     " << delta * i << std::endl;
    }

    for (int i = 0; i < liczba_binow; ++i) std::cout << "-";
    std::cout << std::endl;

    delete[] data;
    std::cout << "Średnia: " << srednia << std::endl;
    std::cout << "Odchylenie standardowe: " << odchylenie << std::endl;
}

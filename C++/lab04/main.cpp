#include "histogram.h"
#include <iostream>

int main(int argc, char* argv[]){
    char tekstura = '|';
    int liczba_binow = 50;
    int wysokosc = 20;
    float x_min = 0;
    float x_max = 1;
    int N = 2;

    if(argc > 1)
        switches(tekstura, liczba_binow, wysokosc, x_min, x_max, N, argc, argv);
    else
        std::cout << "No arguments provided. Using default values.\n";
    
    histogram(tekstura, liczba_binow, wysokosc, x_min, x_max, N);
    return 0;
}

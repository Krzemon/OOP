#include "histogram.h"
#include <iostream>

int main(int argc, char* argv[]){
    char tekstura = '|';    // character representing the histogram
    int liczba_binow = 50;  // number of bins
    int wysokosc = 20;      // height of the histogram
    float x_min = 0;        // lower range of random numbers
    float x_max = 1;        // upper range of random numbers
    int N = 2;              // number of numbers used for calculating the average

    if(argc > 1)
        switches(tekstura, liczba_binow, wysokosc, x_min, x_max, N, argc, argv);
    else
        std::cout << "No arguments provided. Using default values.\n";
    
    histogram(tekstura, liczba_binow, wysokosc, x_min, x_max, N);
    return 0;
}

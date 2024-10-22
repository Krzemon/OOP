#include <iostream>
#include "pascal.h"
#include "sierpinski.h"

int main() {
    int n;
    std::cout << "Podaj ilość wierszy trójkąta Pascala do wypisania: ";
    std::cin >> n;

    std::cout << "\nTrójkąt Pascala:\n";
    pascal(n);

    std::cout << "\nTrójkąt Sierpińskiego:\n";
    sierpinski(n);

    return 0;
}
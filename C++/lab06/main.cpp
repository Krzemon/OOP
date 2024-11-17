#include "vector_matrix.h"
#include <iostream>

int main() {
    Vector<int>* w1 = form_Vector<int>();
    Matrix<int>* m1 = form_Matrix<int>(5, 14);

    std::cout << "To jest napis - funkcja print działa. Działa też dla zmiennych typu bool:\n";
    std::cout << "1\n";

    std::cout << "\nTo jest wektor:\n";
    print_Vector(w1);
    std::cout << "Adres tego wektora to:\n";
    std::cout << w1 << std::endl;

    std::cout << "\nA to jest macierz:\n";
    print_Matrix(m1);
    std::cout << "Adres tej macierzy to:\n";
    std::cout << m1 << std::endl;

    delete_Vector(w1);
    delete_Matrix(m1);

    return 0;
}
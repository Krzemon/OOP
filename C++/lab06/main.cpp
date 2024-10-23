#include "vector_matrix.h"
#include <stdio.h>

int main() {
    Vector *w1 = form_Vector();
    
    Matrix *m1 = form_Matrix(5, 14);

    printf("To jest napis - funkcja print działa. Działa też dla zmiennych typu bool:\n");
    printf("1\n");

    printf("\nTo jest wektor:\n");
    print_Vector(w1);
    printf("Adres tego wektora to:\n");
    printf("%p\n", (void*)w1);

    printf("\nA to jest macierz:\n");
    print_Matrix(m1);
    printf("Adres tej macierzy to:\n");
    printf("%p\n", (void*)m1);

    delete_Vector(w1);
    delete_Matrix(m1);

    return 0;
}

#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H

#include <stdio.h>

typedef struct {
    int x, y, z; // Współrzędne wektora
} Vector;

typedef struct {
    int rows, cols; // Rozmiary macierzy
    int **data;     // Dane macierzy
} Matrix;

// Funkcja do tworzenia wektora i macierzy
Vector* form_Vector();
Matrix* form_Matrix(int rows, int cols);

// Funkcje do usuwania wektora i macierzy
void delete_Vector(Vector *v);
void delete_Matrix(Matrix *m);

// Funkcje do drukowania wektora i macierzy
void print_Vector(const Vector *v);
void print_Matrix(const Matrix *m);

#endif // VECTOR_MATRIX_H
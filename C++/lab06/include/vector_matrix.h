#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H

#include <iostream>

// Szablon dla wektora
template <typename T>
struct Vector {
    T x, y, z;
};

// Szablon dla macierzy
template <typename T>
struct Matrix {
    int rows, cols;
    T **data;
};

// Funkcja do tworzenia wektora
template <typename T>
Vector<T>* form_Vector() {
    Vector<T> *v = new Vector<T>;
    v->x = v->y = v->z = T();
    return v;
}

// Funkcja do tworzenia macierzy
template <typename T>
Matrix<T>* form_Matrix(int rows, int cols) {
    Matrix<T>* m = new Matrix<T>;
    m->rows = rows;
    m->cols = cols;
    m->data = new T*[rows];
    for (int i = 0; i < rows; ++i) {
        m->data[i] = new T[cols];
        for (int j = 0; j < cols; ++j) {
            m->data[i][j] = T();
        }
    }
    return m;
}

// Funkcja do usuwania wektora
template <typename T>
void delete_Vector(Vector<T>* v) {
    delete v;
}

// Funkcja do usuwania macierzy
template <typename T>
void delete_Matrix(Matrix<T>* m) {
    for (int i = 0; i < m->rows; ++i) {
        delete[] m->data[i];
    }
    delete[] m->data;
    delete m;
}

// Funkcja do drukowania wektora
template <typename T>
void print_Vector(const Vector<T>* v) {
    std::cout << "[" << v->x << ", " << v->y << ", " << v->z << "]\n";
}

// Funkcja do drukowania macierzy
template <typename T>
void print_Matrix(const Matrix<T>* m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            std::cout << m->data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif // VECTOR_MATRIX_H

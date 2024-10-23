#include "vector_matrix.h"
#include <stdlib.h>

Vector* form_Vector() {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    if (v == NULL) {
        fprintf(stderr, "Memory allocation failed for vector.\n");
        exit(EXIT_FAILURE);
    }
    v->x = v->y = v->z = 0;
    return v;
}

Matrix* form_Matrix(int rows, int cols) {
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    if (m == NULL) {
        fprintf(stderr, "Memory allocation failed for matrix.\n");
        exit(EXIT_FAILURE);
    }

    m->rows = rows;
    m->cols = cols;
    
    m->data = (int**)malloc(rows * sizeof(int*));
    if (m->data == NULL) {
        fprintf(stderr, "Memory allocation failed for matrix data.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
        if (m->data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for matrix row.\n");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = 0;
        }
    }
    
    return m;
}

void delete_Vector(Vector *v) {
    free(v);
}

void delete_Matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void print_Vector(const Vector *v) {
    printf("[%d, %d, %d]\n", v->x, v->y, v->z);
}

void print_Matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

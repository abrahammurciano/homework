#include <stdio.h>
#include "square_matrix.h"

void print_matrix(SquareMatrix matrix)
{
    for (size_t i = 0; i < matrix.size; ++i)
    {
        for (size_t j = 0; j < matrix.size; ++j)
        {
            printf("%4d ", *get_entry(matrix, i, j));
        }
        printf("\n");
    }
}

int main()
{
    SquareMatrix matrix;
    entry_t values[] = { 1, 2, -3, 4, -2, 6, -7, -8, 3, 7, 11, 12, -4, 8, -12, 16 };
    matrix.entries = values;
    matrix.size = 4;
    printf("Befroe\n");
    print_matrix(matrix);
    MatrixSymmetry symmetry = transpose(matrix);
    printf("After\n");
    print_matrix(matrix);
    printf("The matrix is %ssymmetric\n", (symmetry == SYMMETRIC) ? "" : (symmetry == SKEW_SYMMETRIC) ? "skew " : "not ");
}
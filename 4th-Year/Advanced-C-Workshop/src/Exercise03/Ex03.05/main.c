#include <stdio.h>
#include "square_matrix.h"

void print_matrix(SquareMatrix matrix)
{
    for (size_t i = 0; i < matrix.size; ++i)
    {
        for (size_t j = 0; j < matrix.size; ++j)
        {
            printf("%d\t", *get_entry(matrix, i, j));
        }
        printf("\n");
    }
}

int main()
{
    SquareMatrix matrix;
    entry_t values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    matrix.entries = values;
    matrix.size = 4;
    printf("Befroe\n");
    print_matrix(matrix);
    transpose(matrix);
    printf("After\n");
    print_matrix(matrix);
}
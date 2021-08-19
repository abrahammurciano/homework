#include "square_matrix.h"

void swap(entry_t *a, entry_t *b)
{
    entry_t temp = *a;
    *a = *b;
    *b = temp;
}

void transpose(SquareMatrix matrix)
{
    for (size_t i = 0; i < matrix.size; ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            swap(get_entry(matrix, i, j), get_entry(matrix, j, i));
        }
    }
}

entry_t *get_entry(SquareMatrix matrix, size_t row, size_t col)
{
    return matrix.entries + (row * matrix.size + col);
}
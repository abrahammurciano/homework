#include "square_matrix.h"

void swap(entry_t *a, entry_t *b)
{
    entry_t temp = *a;
    *a = *b;
    *b = temp;
}

MatrixSymmetry entry_symmetry(entry_t a, entry_t b)
{
    return (a == b) ? SYMMETRIC : (a == -b) ? SKEW_SYMMETRIC : NOT_SYMMETRIC;
}

void update_symmetry(MatrixSymmetry *current, entry_t a, entry_t b)
{
    if (*current != entry_symmetry(a, b))
    {
        *current = NOT_SYMMETRIC;
    }
}

MatrixSymmetry transpose(SquareMatrix matrix)
{
    if (matrix.size < 2)
    {
        return  SYMMETRIC;
    }

    MatrixSymmetry symmetry = entry_symmetry(*get_entry(matrix, 0, 1), *get_entry(matrix, 1, 0));

    for (size_t i = 0; i < matrix.size; ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            entry_t *entry_a = get_entry(matrix, i, j);
            entry_t *entry_b = get_entry(matrix, j, i);
            swap(entry_a, entry_b);
            update_symmetry(&symmetry, *entry_a, *entry_b);
        }
    }

    return symmetry;
}

entry_t *get_entry(SquareMatrix matrix, size_t row, size_t col)
{
    return matrix.entries + (row * matrix.size + col);
}
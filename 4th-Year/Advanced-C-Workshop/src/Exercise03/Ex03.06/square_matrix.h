#ifndef square_matrix_h
#define square_matrix_h

#include <stdlib.h>

typedef int entry_t;

/**
 * @brief Represents a square matrix of elements of type entry_t. This struct has two fields. `entries` is an array of size * size elements. `size` is the size of each row and column.
 */
typedef struct SquareMatrix
{
    entry_t *entries;
    size_t size;
} SquareMatrix;

typedef enum MatrixSymmetry
{
    SYMMETRIC, SKEW_SYMMETRIC, NOT_SYMMETRIC
} MatrixSymmetry;

/**
 * @brief Transpose a matrix.
 *
 * @param matrix The matrix to transpose.
 * @return MatrixSymmetry The kind of symmetry of the matrix.
 */
MatrixSymmetry transpose(SquareMatrix matrix);

/**
 * @brief Get the pointer to the matrix entry at the given row and column.
 *
 * @param matrix The matrix whose value to get.
 * @param row The row index.
 * @param col The column index.
 * @return entry_t* A pointer to the matrix entry at the given row and column.
 */
entry_t *get_entry(SquareMatrix matrix, size_t row, size_t col);

#endif
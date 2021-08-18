#ifndef square_matrix_h
#define square_matrix_h

#include <stdlib.h>

typedef int T;

/**
 * @brief Represents a square matrix of elements of type T. This struct has two fields. `entries` is an array of size * size elements. `size` is the size of each row and column.
 */
typedef struct SquareMatrix {
	T* entries;
	size_t size;
} SquareMatrix;

/**
 * @brief Transpose a matrix.
 *
 * @param matrix The matrix to transpose.
 */
void transpose(SquareMatrix matrix);

/**
 * @brief Get the pointer to the matrix entry at the given row and column.
 *
 * @param matrix The matrix whose value to get.
 * @param row The row index.
 * @param col The column index.
 * @return T* A pointer to the matrix entry at the given row and column.
 */
T* get_entry(SquareMatrix matrix, size_t row, size_t col);

#endif
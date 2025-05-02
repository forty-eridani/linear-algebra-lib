#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.h"

typedef struct {
	// Flat matrix 
	double* data;
	int rows;
	int cols;
} Matrix;

// Creates a new matrix. Dynamically allocates memory so must call `FreeMatrix()'
Matrix CreateMatrix(const double* data, int rows, int cols);

// Creates a new product matrix
Matrix MultiplyMatrices(Matrix left, Matrix right);

// Multiples a matrix to a vector, returns a new matrix
Vector MultiplyMatrixToVector(Matrix matrix, Vector vector);

// Returns the sum of two matrices
Matrix AddMatrices(Matrix left, Matrix right);

// Returns the matrix with the applied scalar
Matrix ApplyScalarToMatrix(Matrix matrix, double scalar);

// Frees dynamically allocated memory inside of a matrix
void FreeMatrix(Matrix* matrix);

#endif

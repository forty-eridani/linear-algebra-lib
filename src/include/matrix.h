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

// Create a matrix with all elements set to zero
Matrix CreateMatrixWithZeros(int rows, int cols);

// Does not allocate memory for data, instead fills `.data` field in Matrix with
// given memory address. Do not call `FreeMatrix()` on this object 
Matrix CreateMatrixWithElements(double* data, int rows, int cols);

// Creates a new product matrix
Matrix MultiplyMatrices(Matrix left, Matrix right);

// Multiples a matrix to a vector, returns a new matrix
Vector MultiplyMatrixToVector(Matrix matrix, Vector vector);

// Multplies vector by a matrix in place
void MultiplyMatrixToVectorInPlace(Matrix matrix, Vector* vector);

// Returns the sum of two matrices
Matrix AddMatrices(Matrix left, Matrix right);

// Adds two matrices and stores the sum in the right matrix
void AddMatricesInPlace(Matrix left, Matrix* right);

// Returns the matrix with the applied scalar
Matrix ApplyScalarToMatrix(Matrix matrix, double scalar);

// Applies a scalar to a matrix in place
void ApplyScalarToMatrixInPlace(Matrix* matrix, double scalar);

// Prints the given matrix to stdout
void PrintMatrix(Matrix matrix);

// Frees dynamically allocated memory inside of a matrix
void FreeMatrix(Matrix* matrix);

#endif

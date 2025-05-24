#include "matrix.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_MATRIX (Matrix){.rows = 0.0, .cols = 0.0, .data = NULL}

static int getMatrixIndex(Matrix m, int row, int col) {
	return row * m.cols + col;
}

// You could memset all to zero, but a double is not guaranteed to use IEEE 754
static void setZero(int size, double* data) {
	assert(data);

	for (int i = 0; i < size; i++)
		data[i] = 0.0;
}

Matrix CreateMatrix(const double* data, int rows, int cols) {
	Matrix matrix;

	matrix.cols = cols;
	matrix.rows = rows;
	matrix.data = malloc(rows * cols * sizeof(double));

	memcpy(matrix.data, data, rows * cols * sizeof(double));

	return matrix;
}

Matrix CreateMatrixWithZeros(int rows, int cols) {
	Matrix m;
	
	m.rows = rows;
	m.cols = cols;

	m.data = malloc(rows * cols * sizeof(double));

	setZero(rows * cols, m.data);

	return m;
}

Matrix CreateEmptyMatrix(int rows, int cols) {
	return (Matrix){.rows = rows, .cols = cols, .data = malloc(rows * cols * sizeof(double))};
}

Matrix CreateMatrixWithElements(double* data, int rows, int cols) {
	assert(data);

	return (Matrix){.data = data, .rows = rows, .cols = cols};
}

Matrix MultiplyMatrices(Matrix left, Matrix right) {
	assert(left.data);
	assert(right.data);

	if (left.cols != right.rows) {
		printf("Invalid matrix dimensions for multiplication.\n");
		return EMPTY_MATRIX;
	}

	Matrix product = {.rows = left.rows, .cols = right.cols, .data = malloc(left.rows * right.cols * sizeof(double))};
	setZero(product.cols * product.rows, product.data);

	for (int i = 0; i < right.cols; i++) {
		for (int j = 0; j < right.rows; j++) { 
			int rightScalar = right.data[getMatrixIndex(right, j, i)];

			for (int k = 0; k < left.rows; k++) {
				int productIndex = getMatrixIndex(product, k, i);

				product.data[productIndex] += left.data[getMatrixIndex(left, k, j)] * rightScalar;
			}
		}
	}

	return product;
}

Vector MultiplyMatrixToVector(Matrix matrix, Vector vector) {
	assert(matrix.data);
	assert(vector.data);

	if (matrix.cols != vector.size) {
		printf("Incompatible vector size of %d and matrix width of %d.\n", vector.size, matrix.cols);
		return EMPTY_VECTOR;
	}

	Vector product = {.size = matrix.rows, .data = malloc(matrix.rows * sizeof(double))};

	setZero(product.size, product.data);

	for (int i = 0; i < matrix.cols; i++) {
		for (int j = 0; j < matrix.rows; j++) {
			int matrixIndex = getMatrixIndex(matrix, j, i);
			product.data[j] += vector.data[i] * matrix.data[matrixIndex];
		}
	}

	return product;
}

// Technically not "in place" but I don't care
void MultiplyMatrixToVectorInPlace(Matrix matrix, Vector* vector) {
	assert(vector);
	assert(vector->data);
	assert(matrix.data);

	if (matrix.cols != vector->size || matrix.rows != vector->size) {
		printf("Cannot multiply matrix of uneven dimensions to vector in place.\n");
		return;
	}

	double buf[vector->size];
	setZero(vector->size, buf);

	for (int i = 0; i < vector->size; i++) {
		for (int j = 0; j < matrix.rows; j++) {
			int matrixIndex = getMatrixIndex(matrix, j, i);
			buf[j] += vector->data[i] * matrix.data[matrixIndex];
		}
	}

	memcpy(vector->data, buf, vector->size * sizeof(double));
}

Matrix AddMatrices(Matrix left, Matrix right) {
	assert(left.data);
	assert(right.data);

	if (left.rows != right.rows || left.cols != right.cols) {
		printf("Cannot add matrices of different dimensions.\n");
		return EMPTY_MATRIX;
	}

	Matrix sum = {.cols = left.cols, .rows = left.rows, .data = malloc(left.rows * left.cols * sizeof(double))};

	for (int i = 0; i < left.rows * left.cols; i++) {
		sum.data[i] = left.data[i] + right.data[i];
	}

	return sum;
}

void AddMatricesInPlace(Matrix left, Matrix* right) {
	assert(left.data);
	assert(right);
	assert(right->data);

	if (left.rows != right->rows || left.cols != right->cols) {
		printf("Cannot add matrices of different dimensions.\n");
		return;
	}

	for (int i = 0; i < left.rows * left.cols; i++) {
		right->data[i] += left.data[i];
	}
}

Matrix ApplyScalarToMatrix(Matrix matrix, double scalar) {
	assert(matrix.data);

	Matrix result = {.cols = matrix.cols, .rows = matrix.rows, .data = malloc(matrix.rows * matrix.cols * sizeof(double))};

	for (int i = 0; i < matrix.cols * matrix.rows; i++) {
		result.data[i] = scalar * matrix.data[i];
	}

	return result;
}

void ApplyScalarToMatrixInPlace(Matrix* matrix, double scalar) {
	assert(matrix);
	assert(matrix->data);

	for (int i = 0; i < matrix->cols * matrix->rows; i++) {
		matrix->data[i] *= scalar;
	}
}

void PrintMatrix(Matrix matrix) {
	assert(matrix.data);

	for (int i = 0; i < matrix.rows; i++) {
		printf("[");
		for (int j = 0; j < matrix.cols - 1; j++) {
			printf("%f, ", matrix.data[getMatrixIndex(matrix, i, j)]);
		}
		printf("%f]\n", matrix.data[getMatrixIndex(matrix, i, matrix.cols - 1)]);
	}
}

void FreeMatrix(Matrix* matrix) {
	assert(matrix);

	matrix->rows = 0;
	matrix->cols = 0;

	free(matrix->data);
}

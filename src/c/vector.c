#include "vector.h"
#include <stdlib.h>

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector CreateVector(const double* elements, int size) {
	Vector vector;

	vector.data = malloc(size * sizeof(double));
	vector.size = size;

	memcpy(vector.data, elements, size * sizeof(double)); 

	return vector;
}

Vector CreateVectorWithElements(double* elements, int size) {
	assert(elements);

	return (Vector){.data = elements, .size = size};
}

double VectorSum(Vector v) {
	assert(v.data);

	double sum = 0.0;

	for (int i = 0; i < v.size; i++) {
		sum += v.data[i];
	}

	return sum;
}

double VectorMax(Vector v) {
	assert(v.data);

	double max = v.data[0];

	for (int i = 1; i < v.size; i++)
		if (v.data[i] > max)
			max = v.data[i];

	return max;
}

void AddToVector(Vector v, double x) {
	assert(v.data);

	for (int i = 0; i < v.size; i++)
		v.data[i] += x;
}

Vector AddVectors(Vector v1, Vector v2) {
	assert(v1.data);
	assert(v2.data);

	if (v1.size != v2.size) {
		printf("Cannot add vectors of different sizes.\n");
		return EMPTY_VECTOR;
	}

	Vector sum = {.size = v1.size, .data= malloc(v1.size * sizeof(double))};

	for (int i = 0; i < v1.size; i++) {
		sum.data[i] = v1.data[i] + v2.data[i];
	}

	return sum;
}

void AddVectorsInPlace(Vector v1, Vector* v2) {
	assert(v1.data);
	assert(v2);
	assert(v2->data);

	for (int i = 0; i < v1.size; i++) {
		v2->data[i] += v1.data[i];
	}
}

Vector SubtractVectors(Vector v1, Vector v2) {
	assert(v1.data);
	assert(v2.data);

	if (v1.size != v2.size) {
		printf("Cannot find difference of vectors with different sizes.\n");
		return EMPTY_VECTOR;
	}

	Vector difference = {.size = v1.size, .data = malloc(v1.size * sizeof(double))};

	for (int i = 0; i < v1.size; i++) {
		difference.data[i] = v1.data[i] - v2.data[i];
	}

	return difference;
}

void SubtractVectorsInPlace(Vector v1, Vector* v2) {
	assert(v1.data);
	assert(v2);
	assert(v2->data);

	if (v1.size != v2->size) {
		printf("Cannot find difference of vectors with different sizes.\n");
		return;
	}

	for (int i = 0; i < v1.size; i++) {
		v2->data[i] -= v1.data[i];
	}
}

Vector MultiplyVectors(Vector v1, Vector v2) {
	assert(v1.data);
	assert(v2.data);

	if (v1.size != v2.size) {
		printf("Cannot find product of vectors with different sizes.\n");
		return EMPTY_VECTOR;
	}

	Vector product = {.size = v1.size, .data = malloc(v1.size * sizeof(double))};

	for (int i = 0; i < v1.size; i++) {
		product.data[i] = v1.data[i] * v2.data[i];
	}

	return product;
}

void MultiplyVectorsInPlace(Vector v1, Vector* v2) {
	assert(v1.data);
	assert(v2);
	assert(v2->data);

	if (v1.size != v2->size) {
		printf("Cannot find product of vectors with different sizes.\n");
		return;
	}

	for (int i = 0; i < v1.size; i++) {
		v2->data[i] *= v1.data[i];
	}
}

Vector ApplyScalar(Vector vector, double scalar) {
	assert(vector.data);

	Vector result = CreateVector(vector.data, vector.size);

	for (int i = 0; i < vector.size; i++) {
		result.data[i] *= scalar;
	}

	return result;
}

void ApplyScalarToVectorInPlace(Vector* vector, double scalar) {
	assert(vector);
	assert(vector->data);

	for (int i = 0; i < vector->size; i++)
		vector->data[i] *= scalar;
}

double ComputeNorm(Vector vector) {
	assert(vector.data);

	double sum = 0;

	for (int i = 0; i < vector.size; i++)
		sum += vector.data[i] * vector.data[i];

	return sqrt(sum);
}

void PrintVector(Vector vector) {
	if (vector.size == 0)
		return;

	assert(vector.data);

	for (int i = 0; i < vector.size; i++) {
		printf("[%f]\n", vector.data[i]);
	}
}

void FreeVector(Vector* vector) {
	free(vector->data);
	vector->size = 0;
}

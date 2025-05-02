#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector InitVector(const double* elements, int size) {
	Vector vector;

	vector.data = malloc(size * sizeof(double));
	vector.size = size;

	memcpy(vector.data, elements, size * sizeof(double)); 

	return vector;
}

Vector AddVectors(Vector* v1, Vector* v2) {
	if (v1->size != v2->size) {
		printf("Cannot add vectors of different sizes.\n");
		return EMPTY_VECTOR;
	}

	Vector sum = {.size = v1->size, .data= malloc(v1->size * sizeof(double))};

	for (int i = 0; i < v1->size; i++) {
		sum.data[i] = v1->data[i] + v2->data[i];
	}

	return sum;
}

Vector ApplyScalar(Vector* vector, double scalar) {
	Vector result = InitVector(vector->data, vector->size);

	for (int i = 0; i < vector->size; i++) {
		result.data[i] *= scalar;
	}

	return result;
}

void PrintVector(Vector vector) {
	if (vector.size == 0)
		return;

	for (int i = 0; i < vector.size; i++) {
		printf("[%f]\n", vector.data[i]);
	}
}

void FreeVector(Vector* vector) {
	free(vector->data);
	vector->size = 0;
}

#ifndef VECTOR_H_
#define VECTOR_H_

#define EMPTY_VECTOR (Vector){.size = 0, .data = NULL}

typedef struct {
	double* data;
	int size;
} Vector;

// Initialize a vector with the given elements
Vector InitVector(const double* elements, int size);

// Creates a new vector and so allocated heap memory; must be freed eventually
Vector AddVectors(Vector* v1, Vector* v2);

// Returns a new vector with the scalar applied
Vector ApplyScalarToVector(Vector* vector, double scalar);

// Prints all of the elements of a vector in column form
void PrintVector(Vector vector);

// Deallocate memory for vector elements and set size to 0
void FreeVector(Vector* vector);

#endif

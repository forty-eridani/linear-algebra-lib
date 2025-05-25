#ifndef VECTOR_H_
#define VECTOR_H_

#define EMPTY_VECTOR (Vector){.size = 0, .data = NULL}

typedef struct {
	double* data;
	int size;
} Vector;

// Initialize a vector with the given elements
Vector CreateVector(const double* elements, int size);

// Initializes a vector with all elements set to zero
Vector CreateVectorWithZeros(int size);

// Creates a vector with unitialized values
Vector CreateEmptyVector(int size);

// .data field in struct will be initialized with given memory address; ensure
// object is in scope for less than or equal to the time that elements are in scope
// and avoid freeing 
Vector CreateVectorWithElements(double* elements, int size);

// Computes the sum of all elements in the vector
double VectorSum(Vector v);

// Applies a given function to every element to a vector taking in
// the vector element as an arg to the function
void ApplyFunctionToVector(Vector v, double (*fn)(double));

// Returns the largest element in a vector
double VectorMax(Vector v);

// Add `x` to each element of vector `v`
void AddToVector(Vector v, double x);

// Creates a new vector and so allocated heap memory; must be freed eventually
Vector AddVectors(Vector v1, Vector v2);

// Adds vectors in place and stores the result in the right vector
void AddVectorsInPlace(Vector v1, Vector* v2);

// Finds the difference of two vectors and returns a new difference vector
Vector SubtractVectors(Vector v1, Vector v2);

// Finds the difference of two vectors and stores the difference in the second vector
void SubtractVectorsInPlace(Vector v1, Vector* v2);

// Finds the product of each element of each vector. Not dot or cross product
Vector MultiplyVectors(Vector v1, Vector v2);

// Finds the product of each elements of each vector and stores result in `v2`. Not dot or cross product.
void MultiplyVectorsInPlace(Vector v1, Vector* v2);

// Returns a new vector with the scalar applied
Vector ApplyScalarToVector(Vector vector, double scalar);

// Applies a scalar to a vector and stores the result in place
void ApplyScalarToVectorInPlace(Vector* vector, double scalar);

// Computes the norm (distance) of a given vector
double ComputeNorm(Vector vector);

// Prints all of the elements of a vector in column form
void PrintVector(Vector vector);

// Deallocate memory for vector elements and set size to 0
void FreeVector(Vector* vector);

#endif

#include <stdio.h>

#include "matrix.h"

int main() {
	const double a1[] = {
		1, 2, 3,
		4, 5, 6,
	};

	const double a2[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};

	Matrix m1 = CreateMatrix(a1, 2, 3);
	Matrix m2 = CreateMatrix(a2, 3, 3);

	Matrix product = MultiplyMatrices(m1, m2);

	PrintMatrix(product);

	FreeMatrix(&m1);
	FreeMatrix(&m2);
	FreeMatrix(&product);
}

#include "vector.h"

#include <stdio.h>

double multByTwo(double x) {
	return x * 2;
}

int main() {
	const double v[] = {
		1,
		2,
		3
	};

	Vector vec = CreateVector(v, 3);

	ApplyFunctionToVector(vec, &multByTwo);

	PrintVector(vec);
	printf("%f\n", VectorMax(vec));
}

#include "vector.h"

#include <stdio.h>

int main() {
	const double v[] = {
		1,
		2,
		3
	};

	Vector vec = CreateVector(v, 3);

	AddToVector(vec, 15.0);

	PrintVector(vec);
	printf("%f\n", VectorMax(vec));
}

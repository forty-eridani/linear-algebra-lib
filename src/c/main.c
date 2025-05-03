#include "vector.h"

#include <stdio.h>

int main() {
	const double v[] = {
		1,
		2,
		3
	};

	Vector vec = CreateVector(v, 3);

	printf("%f\n", ComputeNorm(vec));
}

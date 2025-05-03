#include "matrix.h"

#include <stdlib.h>

int main() {
	double matrixData[] = {
		1.2, 1.3, 1.4,
		1.6, 2.1, 4.3
	};

	Matrix m = CreateMatrixWithElements(NULL, 2, 3);

	PrintMatrix(m);
}

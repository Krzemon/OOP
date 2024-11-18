#include "mod_funcs.h"

void randsqr(int n, double* result)
{
	srand(time(NULL));
	double sizes[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double x = rand() / (double)RAND_MAX;
			double y = rand() / (double)RAND_MAX;
			if (x <= sizes[i] && y <= sizes[i])
				++result[i];
		}
		result[i] /= n;
	}
}

double euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclid(b, a%b);
}

#include "Levenshtein_distance.h"

#include <algorithm>
uint32_t Minimum(uint32_t a, uint32_t b, uint32_t c)
{
	if (a > b)
	{
		a = b;
	}
	if (a > c)
	{
		a = c;
	}
	return a;
}
uint32_t Levenshtein_distance(const std::string& a, const std::string& b)
{
	uint32_t n = a.size()+ 1;
	uint32_t m = b.size() + 1;
	int** matrixD = new int* [n];   // создаем 
	for (int i = 0; i < n; i++) {          // двумерный
		matrixD[i] = new int[m]; // массив 
	}

	uint32_t deletionCost = 1;
	uint32_t insertionCost = 1;

	for (uint32_t i = 0; i < n; i++)
	{
		matrixD[i][0] = i;
	}

	for (uint32_t j = 0; j < m; j++)
	{
		matrixD[0][j] = j;
	}

	for (uint32_t i = 1; i < n; i++)
	{
		for (uint32_t j = 1; j < m; j++)
		{
			uint32_t substitutionCost = a[i - 1] == b[j - 1] ? 0 : 1;

			matrixD[i][ j] = Minimum(matrixD[i - 1][ j] + deletionCost,          // delete
				matrixD[i][ j - 1] + insertionCost,         // insert
				matrixD[i - 1][ j - 1] + substitutionCost); // replace
		}
	}
	uint32_t temp = matrixD[n - 1][m - 1];
	for (int i = 0; i < n; i++) {
		delete[] matrixD[i];
	}
	return temp;
}


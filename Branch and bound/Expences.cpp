#include "Expences.h"

Expences::Expences(int **c1, int **c2, int n, int m)
{
	expencesArray1 = new int *[m];
	expencesArray2 = new int *[m];
	this->n = n;
	this->m = m;
	for (int i = 1; i <= m; i++)
	{
		expencesArray1[i] = new int[n];
		expencesArray2[i] = new int[n];
	}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			expencesArray1[i][j] = c1[i][j];
			expencesArray2[i][j] = c2[i][j];
		}
}

int Expences::getExpencesArray1(int i, int j)
{
	return expencesArray1[i][j];
}

int Expences::getExpencesArray2(int i, int j)
{
	return expencesArray2[i][j];
}

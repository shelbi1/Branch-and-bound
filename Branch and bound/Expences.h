#pragma once

// Класс для матриц затрат 
class Expences
{
	int **expencesArray1;
	int **expencesArray2;
	int n, m;
public:
	Expences(int **c1, int **c2, int n, int m);
	int getExpencesArray1(int i, int j);
	int getExpencesArray2(int i, int j);
};
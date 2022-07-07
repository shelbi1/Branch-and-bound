#include "Objects.h"
#include "Expences.h"
#include <iostream>

Objects::Objects(int n, int m)
{
	this->n = n;
	this->m = m;
	objects = new Obj[n];
	for (int j = 1; j <= n; j++)
	{
		objects[j].objectNum = j;
		objects[j].isVisited = notVisited;
	}

	centers = new int[m];
	for (int i = 1; i <= m; i++)
	{
		centers[i] = i;
	}
}

int Objects::getN()
{
	return n;
}

int Objects::getM()
{
	return m; 
}

void Objects::tagObject(int num)
{
	objects[num].isVisited = visited;
}

bool Objects::allObjectsTagged()
{
	for (int j = 1; j <= n; j++)
	{
		if (objects[j].isVisited != visited)
			return false;
	}
	return true;
}

int Objects::getFirstUntagged()
{
	for (int j = 1; j <= n; j++)
	{
		if (objects[j].isVisited != visited)
			return j;
	}
}

void Objects::untagObjects()
{
	for (int j = 1; j <= n; j++)
	{
		objects[j].isVisited = notVisited;
	}
}

IsVisited Objects::checkTag(int objectNum)
{
	if (objects[objectNum].isVisited == visited)
		return visited;
	else
		return notVisited;
}

int Objects::objectsNumberOfPermutations()
{
	int nFac = 1; 
	for (int j = 1; j <= n; j++)
		nFac *= j;
	return nFac; 
}

int Objects::centersNumberOfPermutations()
{
	return pow(n - 1, m);
}

void swap(int *a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool NextSet1(int *a, int n)
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false; // больше перестановок нет
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	swap(a, j, k);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l<r)
		swap(a, l++, r--);
	return true;
}
void Print(int *a, int n) 
{
	static int counter = 1; 
	std::cout.width(3); // ширина поля вывода номера перестановки
	std::cout << counter++ << ": ";
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

// двумерный массив, хранящий в себе все перестановки без повторений целевых объектов
int **Objects::objectsPermutations()
{
	int nFac = objectsNumberOfPermutations(); 
	int **objectPermutations = new int*[nFac];
	for (int i = 0; i < nFac; i++)
		objectPermutations[i] = new int[n];

	int *arrayObjects = new int[n]; 
	for (int j = 0; j < n; j++)
	{
		objectPermutations[0][j] = objects[j + 1].objectNum;
		arrayObjects[j] = objectPermutations[0][j]; 
	}

	for (int i = 0; i < nFac; i++)
	{
		//Print(arrayObjects, n);
		for (int j = 0; j < n; j++)
		{
			// сохраняем значение i - итерация перебора всех значений объектов. сохраняем в i строчку
			objectPermutations[i][j] = arrayObjects[j];
		}
		// перебор всех значений 
		NextSet1(arrayObjects, n);
	}
	
	return objectPermutations; 
}


static int index = 0;
void Generate(int k, int K, int M, int **&centersPermutations, int *arrayCenters)
{
	if (k == K)
	{
		for (int i = 0; i < K; i++)
			centersPermutations[index][i] = arrayCenters[i];
		index++;
	}
	else
	{
		for (int j = 0; j < M; j++)
		{
			arrayCenters[k] = j + 1;
			Generate(k + 1, K, M, centersPermutations, arrayCenters);
		}
	}
}

// двумерный массив, хранящий в себе все возможные перестановки с повторениями центров  
int **Objects::centersPermutations()
{
	int mFac = centersNumberOfPermutations();
	int **centersPermutations = new int*[mFac];
	for (int i = 0; i < mFac; i++)
		centersPermutations[i] = new int[getM()];

	int *arrayCenters = new int[m];
	for (int i = 0; i < m; i++)
	{
		centersPermutations[0][i] = centers[i + 1];
		arrayCenters[i] = centersPermutations[0][i];
	}

	// количество возможных постановок с повторениями центров напрямую зависит от количества объектов  
	int K = n - 1;
	int M = m; // количество центров 

	/// K - длина набора, M - количество цифр (в данному случае центров) в переборе

	Generate(0, K, M, centersPermutations, arrayCenters);
	/*	for debug only 

	for (int i = 0; i < mFac; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << centersPermutations[i][j] << " ";
		std::cout << std::endl;
	}
	*/
	index = 0; 
	return centersPermutations;
}


int Objects::getFirstMinCenter(Expences expences, int objectNum)
{
	int min = 999999;
	int index = 999999;
	for (int i = 1; i <= m; i++)
	{
		if (expences.getExpencesArray2(i, objectNum) < min)
		{
			min = expences.getExpencesArray2(i, objectNum);
			index = i;
		}
	}
	return index;
}

#pragma once
#include "Expences.h"

enum IsVisited
{
	visited,
	notVisited
};
struct Obj
{
	int objectNum;
	IsVisited isVisited;
};

// Класс для хранения всех объектов. в течение работы программы будем помечать номера посещённых целевых объектов
class Objects
{
	Obj *objects; // целевые объекты
	int *centers; // центры
	int n, m;
public:
	Objects(int n, int m);
	int getN();
	int getM(); 
	void tagObject(int num);
	bool allObjectsTagged();
	int getFirstUntagged();
	void untagObjects();
	IsVisited checkTag(int objectNum);

	int objectsNumberOfPermutations();	// перестановки без повторений для объектов 
	int centersNumberOfPermutations();	// перестановки с повторениями для центров 

	int **objectsPermutations(); 
	int **centersPermutations();

	int getFirstMinCenter(Expences expences, int objectNum); // получение номера центра с минимальным расстоянием от объекта
};
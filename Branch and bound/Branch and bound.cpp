#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std; 

/* 
Сделано: 
1. В лист добавить матрицу расстояний и список уже пройденных городов

Сделать:

	-1. Красивый вывод с | для понимания
	
	1. Реализовать стратегию вниз по левой ветви и вверх до ближайшей доступной (обход в глубину) 
	2. как мы будем чередовать перемещение от объекта к объекту? записывать в список? 
		ввести условия для разных матмоделей 
	
	?. В конце вывести минимальный маршрут допустим как: 3 -> 1 -> 4 -> 2 = 536
*/
void inputFromFile(ifstream &file, int **&c, int &n, int &m);

int main()
{
	setlocale(LC_ALL, "Russian"); 
	ifstream data1("input1.txt"); // информация о затратах передвежения с центра в объект 
	ifstream data2("input2.txt"); // затраты объект -> центр
	if (!data1.is_open() && !data2.is_open())
		cout << "Ошибка в открытии файлов" << endl;
	else
	{
		int n; // объекты
		int m; // центры
		int **c1, **c2;
		inputFromFile(data1, c1, n, m);
		inputFromFile(data2, c2, n, m);
		Tree tree;
		TreeNode root = new Node(1);
		tree.create(tree, root, n);
		tree.printTree(root, n);
		tree.clearTree(root);

		cout << "Введите номер центра с которого начнём: ";
		int first;
		cin >> first;
		cout << "Маршруты, с заданного начального центра " << first << ":";

		cout << "Маршрут с минимальным расстоянием: ";
	}
	system("pause"); 
	data1.close();
	data2.close();
	return 0; 
}


void inputFromFile(ifstream &file, int **&c, int &n, int &m)
{
	file >> n >> m;
	// инициализация двумерного массива 
	c = new int *[m];
	for (int i = 1; i <= m; i++)
		c[i] = new int[n];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = 0;

	int firstNumber, secondNumber, expences;
	while (!file.eof())
	{
		file >> firstNumber;
		file >> secondNumber;
		file >> expences;
		c[firstNumber][secondNumber] = expences;
	}
}

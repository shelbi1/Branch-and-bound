#include "stdafx.h"
#include "Tree.h"
#include "RouteList.h"
#include <iostream>
#include <fstream>
using namespace std; 

/* 
Сделано: 
1. В лист добавить матрицу расстояний и список уже пройденных городов
2. разобраться с выводом всех значений вектора.
3. 	зациклить, чтобы в список добавлялись разные комбинации head
4. 	вывести инициализацию objectPermutations в отдельную функцию 
	ну и количество перестановок с повторами и без в отдельную и затем вызывать в permutations 
Сделать:


	?. затем перенести списки в бинарное дерево и добавить в него обход в глубину. ну и красивый вывод

	-1. Красивый вывод с | для понимания
	
	1. Реализовать стратегию вниз по левой ветви и вверх до ближайшей доступной (обход в глубину) 
	2. как мы будем чередовать перемещение от объекта к объекту? записывать в список? 
		ввести условия для разных матмоделей 
	
	3. Работать со списком пройденного маршрута, задействовать функцию для возможного перебора всех объектов.
	Прописать условия, которые ограничивают повторое посещение объектов (возможно не понадобится, тк просто 
	будем убирать из списка вершину). 
	4. Перенести void createRoute(); 
	void objectRearrangement(Expences expences); в RouteList


	Короче сначала нужно разобраться со всеми возможными перестановками в маршруте RouteList, 
	затем с выводом минимального маршрута, 
	затем приплетать к этому бинарное дерево, выдумывать обходы разными стратегиями, 
	в том числе и с метками (спросить с утра как это сделать) 



	?. В конце вывести минимальный маршрут допустим как: 3 -> 1 -> 4 -> 2 = 536
	cout << "Маршрут с минимальным расстоянием: ";
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

		cout << "Введите номер центра с которого начнём: ";



		int centerNum = 1; //убрать
		//cin >> centerNum; //вернуть


		if (centerNum > m || centerNum < 0)
		{
			cout << "Неправильный выбор номера центра" << endl; 
		}
		else
		{
			cout << "Маршруты, с заданного начального центра " << centerNum << ": " << std::endl;
			RouteList routeList;
			Objects objects(n, m);
			Expences expences(c1, c2, n, m); 

			std::vector<RouteList*> lists = routeList.objectRearrangement(expences, objects, centerNum);
			routeList.printLists(lists); 

			Tree tree;
			TreeNode root = new Node(1);
			tree.create(tree, root, n);
			tree.printTree(root, n);
			tree.clearTree(root);
		}
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

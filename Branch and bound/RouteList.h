#pragma once
#include <iostream>
#include <vector>
#include "Expences.h"
#include "Objects.h"

/*
	переделать функцию перестановок всех значений (возвращаем массив массивов, 
		где каждая строчка отвечает за перебор значений одного набора (разобраться с границами массивов... [1;n]

	также каждую итерацию добавлять набор перестановок в objectPermutations[counter]

*/

enum Type
{
	notGivenYet,
	object,
	center
};

class RouteList
{
public:
	Type type;
	int objectNumber;
	int currentExpences;
	RouteList * next;

	RouteList(); 
	bool isEmpty(RouteList *head);									// проверка на пустоту 
	void addToHead(RouteList *&head, Type type, int object);		// добавление в начало
	void addAfterNode(RouteList *&pNode, Expences expences,
		Type type, int objectNum, int centerNum);					// добавление после элемента  
	int saveExpences(int expences);									// сохранение значения затрат 
	void printLists(std::vector<RouteList*> head);					// печать списков
	void printList(RouteList *head);								// печать списка 

	std::vector<RouteList*> objectRearrangement(Expences exp, Objects obj, int num);// перестановка всех возможных путей
	int permutations(Objects objects);

	int addCenterAfterObject(RouteList *&p, Expences expences, Objects objects, int objectNum);
	int addObjectAfterCenter(RouteList *&p, Expences expences, Objects objects, int centerNum);
	RouteList* createList(Expences expences, Objects objects, RouteList *&head, int centerStartNum);
};
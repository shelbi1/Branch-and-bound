#pragma once
#include <iostream>

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
	RouteList * next;
};

typedef RouteList * TList;
														   
void init(TList &head);						 			// инициалиция
bool isEmpty(TList head);								// проверка на пустоту 
void addToHead(TList &head, int object, Type type);		// добавление в начало
void addAfterNode(TList pNode, int object, Type type);	// добавление после элемента  
void deleteFromHead(TList &head);						// удаление с начала списка 
void deleteAfterNode(TList pNode);						// удаление после заданного элемента 

void deleteObject(int objectNumber);					// удаление элемента по типу (объект) и его номеру

void clear(TList &head);								// очистка списка 
void printList(TList head);								// печать списка
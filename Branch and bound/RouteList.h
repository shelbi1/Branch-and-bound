#pragma once
#include <iostream>
#include <vector>
#include "Expences.h"
#include "Objects.h"

/*
	���������� ������� ������������ ���� �������� (���������� ������ ��������, 
		��� ������ ������� �������� �� ������� �������� ������ ������ (����������� � ��������� ��������... [1;n]

	����� ������ �������� ��������� ����� ������������ � objectPermutations[counter]

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
	bool isEmpty(RouteList *head);									// �������� �� ������� 
	void addToHead(RouteList *&head, Type type, int object);		// ���������� � ������
	void addAfterNode(RouteList *&pNode, Expences expences,
		Type type, int objectNum, int centerNum);					// ���������� ����� ��������  
	int saveExpences(int expences);									// ���������� �������� ������ 
	void printLists(std::vector<RouteList*> head);					// ������ �������
	void printList(RouteList *head);								// ������ ������ 

	std::vector<RouteList*> objectRearrangement(Expences exp, Objects obj, int num);// ������������ ���� ��������� �����
	int permutations(Objects objects);

	int addCenterAfterObject(RouteList *&p, Expences expences, Objects objects, int objectNum);
	int addObjectAfterCenter(RouteList *&p, Expences expences, Objects objects, int centerNum);
	RouteList* createList(Expences expences, Objects objects, RouteList *&head, int centerStartNum);
};
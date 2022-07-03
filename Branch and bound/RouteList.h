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
														   
void init(TList &head);						 			// �����������
bool isEmpty(TList head);								// �������� �� ������� 
void addToHead(TList &head, int object, Type type);		// ���������� � ������
void addAfterNode(TList pNode, int object, Type type);	// ���������� ����� ��������  
void deleteFromHead(TList &head);						// �������� � ������ ������ 
void deleteAfterNode(TList pNode);						// �������� ����� ��������� �������� 

void deleteObject(int objectNumber);					// �������� �������� �� ���� (������) � ��� ������

void clear(TList &head);								// ������� ������ 
void printList(TList head);								// ������ ������
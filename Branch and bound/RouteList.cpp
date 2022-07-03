#include "RouteList.h"
#include <iostream>

void init(TList &head)
{
	head->type = notGivenYet;
	head->objectNumber = 0; 
	head->next = nullptr; 
}

bool isEmpty(TList head)
{
	return head == nullptr; 
}

void addToHead(TList &head, int object, Type type)
{
	TList p = new RouteList;
	p->objectNumber = object;
	p->type = type;
	p->next = head;
	head = p;
}

void addAfterNode(TList pNode, int object, Type type)
{
	TList p = new RouteList;
	p->objectNumber = object;
	p->type = type;
	p->next = pNode->next;
	pNode->next = p;
}

void deleteFromHead(TList &head)
{
	TList p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
}

void deleteAfterNode(TList pNode)
{
	if (pNode != nullptr)
	{
		TList p = pNode->next;
		pNode->next = p->next;
		p->next = nullptr;
		delete p;
	}
}

void deleteObject(int objectNumber)
{

}

void clear(TList &head)
{
	while (!isEmpty(head))
		deleteFromHead(head);
	delete head;
}

void printList(TList head)
{
	TList p = head;
	while (p != nullptr)
	{
		std::cout << p->objectNumber << " " << p->type << std::endl;
		p = p->next;
	}
}
#include "RouteList.h"
#include <iostream>
#include <vector>

RouteList::RouteList()
{
	this->type = notGivenYet;
	this->objectNumber = 0; 
	this->currentExpences = 0; 
	this->next = nullptr; 
}

bool RouteList::isEmpty(RouteList *head)
{
	return head == nullptr; 
}

void RouteList::addToHead(RouteList *&head, Type type, int object)
{
	RouteList *p = new RouteList;
	p->type = type;
	p->objectNumber = object;
	p->currentExpences = 0;
	p->next = head;
	head = p;
}

int saveExp = 0;
void RouteList::addAfterNode(RouteList *&pNode, Expences expences, Type type, int objectNum, int centerNum)
{
	RouteList *p = new RouteList;
	p->type = type;
	if (type == object)
	{
		p->objectNumber = objectNum;
		saveExpences(expences.getExpencesArray1(centerNum, objectNum));
		p->currentExpences = saveExp; 
	}
	else
	{
		p->objectNumber = centerNum;
		saveExpences(expences.getExpencesArray2(centerNum, objectNum));
		p->currentExpences = saveExp;
	}
	p->next = pNode->next;
	pNode->next = p;
}

int RouteList::saveExpences(int expences)
{
	saveExp += expences; 
	return saveExp;
}

void RouteList::printLists(std::vector<RouteList*> head)
{
	// работа с итераторами вектора
	for (std::vector<RouteList*>::iterator it = head.begin(); it != head.end(); ++it)
	{
		printList(*it);
		std::cout << std::endl;
	}
}

void RouteList::printList(RouteList *head)
{
	RouteList *p = head; 
	while (p->type != notGivenYet)
	{
		std::cout << p->objectNumber;
		if (p->type == object)
			std::cout << ".object";
		else
			std::cout << ".center";

		if (p->next->type != notGivenYet)
			std::cout << " -> ";
		else
			std::cout << std::endl << "Current expences: " << p->currentExpences << std::endl;

		p = p->next;
	}
}

int iterationForObjects = 0, iterationForCenters = 0;
int visitObject = 0, visitCenter = 0;
std::vector<RouteList *> RouteList::objectRearrangement(Expences expences, Objects objects, int centerStartNum)
{
	// вектор списков разных маршрутов, начиная с заданного центра
	std::vector<RouteList *> routeLists; 

	//количество возможных перестановок с заданного центра 
	for (int i = 1; i <= permutations(objects); i++)
	{
		RouteList *head = new RouteList;
		createList(expences, objects, head, centerStartNum);
		routeLists.push_back(head);				 //добавляем список в наш вектор списков в конец
		objects.untagObjects(); 
		/* 
		чтобы не выйти за границы возможного количества перестановок объектов при разных комбинациях центров
		(это перемножение всех перестановок центров и объектов, мы ограничиваем их) 
		*/
		iterationForObjects++;
		iterationForCenters++;
		if (iterationForObjects >= objects.objectsNumberOfPermutations())
			iterationForObjects = iterationForObjects % objects.objectsNumberOfPermutations();
		if (iterationForCenters >= objects.centersNumberOfPermutations())
			iterationForCenters = iterationForCenters % objects.centersNumberOfPermutations();

		visitObject = 0; 
		visitCenter = 0;
		saveExp = 0;
	}
	return routeLists; 
};

int RouteList::permutations(Objects objects)
{
	return 	objects.centersNumberOfPermutations() * objects.objectsNumberOfPermutations();
	// перестановки с повторениями для центров  * перестановки без повторений для объектов 
}

int RouteList::addCenterAfterObject(RouteList *&p, Expences expences, Objects objects, int objectNum)
{
	//int centerNum = objects.getFirstMinCenter(expences, objectNum);

	int mFac = objects.centersNumberOfPermutations();
	int **centersPermutations = new int*[mFac];
	for (int i = 1; i <= mFac; i++)
		centersPermutations[i] = new int[objects.getM()];
	centersPermutations = objects.centersPermutations();
	int centerNum = centersPermutations[iterationForCenters][visitCenter];
	addAfterNode(p, expences, center, objectNum, centerNum);
	p = p->next;
	visitCenter++; 
	return centerNum; 
}

int RouteList::addObjectAfterCenter(RouteList *&p, Expences expences, Objects objects, int centerNum)
{
	//int objectNum = objects.getFirstUntagged(); 

	int nFac = objects.objectsNumberOfPermutations();
	int **objectsPermutations = new int*[nFac];
	for (int j = 1; j <= nFac; j++)
		objectsPermutations[j] = new int[objects.getN()];

	objectsPermutations = objects.objectsPermutations();
	int objectNum = objectsPermutations[iterationForObjects][visitObject];
	addAfterNode(p, expences, object, objectNum, centerNum);
	objects.tagObject(objectNum);
	p = p->next;
	visitObject++;
	return objectNum;
}

RouteList* RouteList::createList(Expences expences, Objects objects, RouteList *&head, int centerStartNum)
{
	int centerNum, objectNum;
	
	// добавляем первый центр в список, из которого начинаем
	addToHead(head, center, centerStartNum); 
	RouteList *p = head;
	centerNum = centerStartNum;

	while (!objects.allObjectsTagged())
	{
		// добавление в список ещё не посещённого целевого объекта
		objectNum = addObjectAfterCenter(p, expences, objects, centerNum);

		if (!objects.allObjectsTagged())
		{
			//добавление ближайшего центра после целевого объекта 
			centerNum = addCenterAfterObject(p, expences, objects, objectNum);
		}
		else
		{
			// возвращаемся в начальный центр 
			addAfterNode(p, expences, center, objectNum, centerStartNum);
		}
	}

	return head; 
}
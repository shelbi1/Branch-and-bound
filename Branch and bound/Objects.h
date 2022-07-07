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

// ����� ��� �������� ���� ��������. � ������� ������ ��������� ����� �������� ������ ���������� ������� ��������
class Objects
{
	Obj *objects; // ������� �������
	int *centers; // ������
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

	int objectsNumberOfPermutations();	// ������������ ��� ���������� ��� �������� 
	int centersNumberOfPermutations();	// ������������ � ������������ ��� ������� 

	int **objectsPermutations(); 
	int **centersPermutations();

	int getFirstMinCenter(Expences expences, int objectNum); // ��������� ������ ������ � ����������� ����������� �� �������
};
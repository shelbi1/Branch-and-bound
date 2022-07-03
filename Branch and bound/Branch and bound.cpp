#include "stdafx.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std; 

/* 
�������: 
1. � ���� �������� ������� ���������� � ������ ��� ���������� �������

�������:

	-1. �������� ����� � | ��� ���������
	
	1. ����������� ��������� ���� �� ����� ����� � ����� �� ��������� ��������� (����� � �������) 
	2. ��� �� ����� ���������� ����������� �� ������� � �������? ���������� � ������? 
		������ ������� ��� ������ ���������� 
	
	?. � ����� ������� ����������� ������� �������� ���: 3 -> 1 -> 4 -> 2 = 536
*/
void inputFromFile(ifstream &file, int **&c, int &n, int &m);

int main()
{
	setlocale(LC_ALL, "Russian"); 
	ifstream data1("input1.txt"); // ���������� � �������� ������������ � ������ � ������ 
	ifstream data2("input2.txt"); // ������� ������ -> �����
	if (!data1.is_open() && !data2.is_open())
		cout << "������ � �������� ������" << endl;
	else
	{
		int n; // �������
		int m; // ������
		int **c1, **c2;
		inputFromFile(data1, c1, n, m);
		inputFromFile(data2, c2, n, m);
		Tree tree;
		TreeNode root = new Node(1);
		tree.create(tree, root, n);
		tree.printTree(root, n);
		tree.clearTree(root);

		cout << "������� ����� ������ � �������� �����: ";
		int first;
		cin >> first;
		cout << "��������, � ��������� ���������� ������ " << first << ":";

		cout << "������� � ����������� �����������: ";
	}
	system("pause"); 
	data1.close();
	data2.close();
	return 0; 
}


void inputFromFile(ifstream &file, int **&c, int &n, int &m)
{
	file >> n >> m;
	// ������������� ���������� ������� 
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

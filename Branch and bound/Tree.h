#pragma once
#include "stdafx.h"
#include <iostream>
#include <set>
#include "RouteList.h"

class Label
{
	int label; 
public:
	int Random();
	int GetLabel();
};

// ����� ��� �������� ���� ������� ��������. � ������� ������ ��������� ����� ������� ������ ����������
class Objects
{
	int **objects;
};

// ����� ��� ������� ������ 
class Expences
{
	int **expencesArray;
};

struct Node
{
	RouteList route;		// �������, ������ ���������� �������/��������
	int mark; 
	int currentExpences; 
	Label label;

	Node * left;
	Node * right;

	Node();														
	Node(int value);		
	void createRoute(); 
	void objectRearrangement(Expences expences); // ������������ ���� ��������� ����� 
	// �������� ������� ��� ������������ 
};

typedef Node* TreeNode;

class Tree
{
private:
	TreeNode root;
	Expences expences; 

public:
	Tree();														
	~Tree();													

	TreeNode getRoot();											
	bool isTreeEmpty();
	TreeNode create(Tree tree, TreeNode &root, int n);
	void insert(TreeNode &T, int value);
	// �������� ����� ��������� ������ � �������
	void printTree(TreeNode T, int level);						
	void clearTree(TreeNode &T);								
};
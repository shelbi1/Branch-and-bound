#pragma once
#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>

class Label
{
	int label; 
	int city; 
public:
	int Random(int value);
	int GetLabel();
};

struct Node
{
	// добавить матрицу расстояний, пройденный маршрут как список 
	int data;
	int mark; 
	Node * left;
	Node * right;

	Label label; 
	Node();														
	Node(int value);				
};

typedef Node* TreeNode;

class Tree
{
private:
	TreeNode root;

public:
	Tree();														
	~Tree();													

	TreeNode getRoot();											
	bool isTreeEmpty();
	TreeNode create(Tree tree, TreeNode &root, int n);
	void insert(TreeNode &T, int value);							
	void printTree(TreeNode T, int level);						
	void clearTree(TreeNode &T);								
};
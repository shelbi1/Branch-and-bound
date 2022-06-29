#include "stdafx.h"
#include "Tree.h"
#include <iostream>

using namespace std; 

set <int> nonRepeatingLabels;

int Label::Random(int value)
{
	/*
	������� �������� ������� ��������� ��������������� ��������� � ��������� � 1 �� 100
	���������� ����� � ���������� �����
	*/

	city = value;
	int newNumber = rand() % 99; 
	nonRepeatingLabels.insert(newNumber);
	// ���� ������� �� ������, �� ������������ ������� ����� ���������� (.end())
	if (nonRepeatingLabels.find(newNumber) != nonRepeatingLabels.end())
	{
		label = newNumber;
	}
	else
	{
		newNumber = rand() % 99;
		nonRepeatingLabels.insert(newNumber);
		label = newNumber;
	}

	return label; 
}

int Label::GetLabel()
{
	return label;
}

Node::Node()
{
	data = 0;
	mark = label.Random(data);
	left = nullptr;
	right = nullptr;
}

Node::Node(int value)
{
	data = value;
	mark = label.Random(data);
	left = nullptr;
	right = nullptr;
}

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	if (root != nullptr)
		delete root;
}

TreeNode Tree::getRoot()
{
	return root;
}

bool Tree::isTreeEmpty()
{
	return (root == nullptr);
}

TreeNode Tree::create(Tree tree, TreeNode &root, int n)
{
	//for (int i = 2; i <= n; i++)
		//tree.insert(root, i);
	/*
		tree.insert(root, 1);
		tree.insert(root, 4);
		tree.insert(root, 2);
	*/
	return root;
}

void Tree::insert(TreeNode &T, int value)
{
	if (T == nullptr)
	{
		T = new Node;
		T->left = nullptr;
		T->right = nullptr;
		T->data = value;
		T->mark = T->label.GetLabel();
	}
	else
	{
		if (value < T->data)
			insert(T->left, value);
		else
			insert(T->right, value);
	}
}

void Tree::printTree(TreeNode T, int level)
{
	if (T != nullptr)
	{
		printTree(T->right, level + 1);

		for (int i = 1; i <= level; i++)
			std::cout << "   ";

		std::cout << T->data << std::endl;

		printTree(T->left, level + 1);
	}
}

void Tree::clearTree(TreeNode &T)
{
	if (T != nullptr)
	{
		clearTree(T->left);
		clearTree(T->right);
		delete T;
		T = nullptr;
	}
}



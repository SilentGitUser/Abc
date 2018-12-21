#include <ctime>
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Tree.h"

using namespace std;


template <typename T>
class Tree;

template <typename T>
class Tree
{
	friend clock_t TreeSort(Tree* arr, int size);
	Tree* left;
	Tree* right;
	T k;
	
public:
	static int index;
	Tree(T data)
	{
		k = data;
		left = right = NULL;
	}

	Tree()
	{
		k = NULL;
		left = right = NULL;
	}

public:
	void insert_recursive(Tree*);
	void visit(T* SortArr);
	void visit_recursive(T* SortArr);
};

template <typename T>
void Tree<T>::insert_recursive(Tree<T>* tree_to_insert)
{
	if (this->k > tree_to_insert->k)
	{
		if (this->left == NULL)
		{
			this->left = tree_to_insert;
			return;
		}
		this->left->insert_recursive(tree_to_insert);
	}
	else
	{
		if (this->right == NULL)
		{
			this->right = tree_to_insert;
			return;
		}
		this->right->insert_recursive(tree_to_insert);
	}
}

template <typename T>
void Tree<T>::visit_recursive(T* SortArr)
{
	if (this->left != NULL)
		this->left->visit_recursive(SortArr);

	this->visit(SortArr);

	if (this->right != NULL)
		this->right->visit_recursive(SortArr);

}

template <typename T>
void Tree<T>::visit(T *SortArr)
{
	//cout << this->k << " ";
	*(SortArr + index) = this->k;
	index++;
}



template <typename T>
int Tree<T>::index = 0;


template <typename T>
clock_t TreeSort(T* arr, int size)
{
	Tree<T>* arrTree = new Tree<T>[size];
	Tree<T>::index = 0;
	clock_t starttime = clock();
	for (int i = 0; i < size; i++)
	{
		arrTree[i] = Tree<T>(arr[i]);
	}

	for (int i = 1; i < size; i++)
	{
		arrTree[0].insert_recursive(&arrTree[i]);
	}

	arrTree[0].visit_recursive(arr);

	delete[] arrTree;

	clock_t	endtime = clock();
	clock_t diftime = endtime - starttime;
	return diftime;
}
// ArrayTask2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;

class Tree;

template <typename T>
void ShowArr(string str, T* arr, int size);


class Tree
{
	Tree* left;
	Tree* right;
	int k;
	Tree* m_root;
public:
	Tree(int data)
	{
		k = data;
		left = right = m_root = NULL;

	}
	
	Tree()
	{
		k = 0;
		left = right = m_root = NULL;
	}

public:
	void insert_recursive(Tree*);
	void visit(Tree* );
	void visit_recursive(Tree* );
};


void Tree::insert_recursive(Tree* tree_to_insert)
{
	if (this->k < tree_to_insert->k)
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

void Tree::visit_recursive(Tree* root)
{
	if (root->left != NULL)
		visit_recursive(root->left);

	visit(root);

	if (root->right != NULL)
			visit_recursive(root->right);

}

void Tree::visit(Tree* root)
{
	cout << root->k << "  ";
}

int main()
{
	int const ArrSize = 10;
	srand(clock());

	Tree* ArrTreeInt = new Tree[ArrSize];

	char* ArrChar = new char[ArrSize];
	int* ArrInt = new int[ArrSize];
	long* ArrLong = new long[ArrSize];
	float* ArrFloat = new float[ArrSize];
	double* ArrDouble = new double[ArrSize];
	/*char* ArrChar2 = new char[ArrSize];
	int* ArrInt2 = new int[ArrSize];
	long* ArrLong2 = new long[ArrSize];
	float* ArrFloat2 = new float[ArrSize];
	double* ArrDouble2 = new double[ArrSize];
	char* ArrChar3 = new char[ArrSize];
	int* ArrInt3 = new int[ArrSize];
	long* ArrLong3 = new long[ArrSize];
	float* ArrFloat3 = new float[ArrSize];
	double* ArrDouble3 = new double[ArrSize];
	char* ArrChar4 = new char[ArrSize];
	int* ArrInt4 = new int[ArrSize];
	long* ArrLong4 = new long[ArrSize];
	float* ArrFloat4 = new float[ArrSize];
	double* ArrDouble4 = new double[ArrSize];*/


	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i] + 0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);

		ArrTreeInt[i] = Tree(ArrInt[i]);

		/*ArrChar2[i] = ArrChar[i];
		ArrInt2[i] = ArrInt[i];
		ArrLong2[i] = ArrLong[i];
		ArrFloat2[i] = ArrFloat[i];
		ArrDouble2[i] = ArrDouble[i];

		ArrChar3[i] = ArrChar[i];
		ArrInt3[i] = ArrInt[i];
		ArrLong3[i] = ArrLong[i];
		ArrFloat3[i] = ArrFloat[i];
		ArrDouble3[i] = ArrDouble[i];

		ArrChar4[i] = ArrChar[i];
		ArrInt4[i] = ArrInt[i];
		ArrLong4[i] = ArrLong[i];
		ArrFloat4[i] = ArrFloat[i];
		ArrDouble4[i] = ArrDouble[i];*/
	}

	/*cout << "ArraySize= " << ArrSize << endl;
	ShowArr("Unsorted char array:", ArrChar, ArrSize);*/
	ShowArr("Unsorted int array:", ArrInt, ArrSize);
	/*ShowArr("Unsorted long array:", ArrLong, ArrSize);
	ShowArr("Unsorted float array:", ArrFloat, ArrSize);
	ShowArr("Unsorted double array:", ArrDouble, ArrSize);*/

	/*clock_t TimeExtremeChar = extreme(ArrChar, ArrSize);
	cout << "\nTime elapsed for Char   extreme sort: " << TimeExtremeChar << " ms" << endl;
	clock_t TimeExtremeLong = extreme(ArrLong, ArrSize);
	cout << "Time elapsed for Long   extreme sort: " << TimeExtremeLong << " ms" << endl;
	clock_t TimeExtremeInt = extreme(ArrInt, ArrSize);
	cout << "Time elapsed for Int    extreme sort: " << TimeExtremeInt << " ms" << endl;
	clock_t TimeExtremeFloat = extreme(ArrFloat, ArrSize);
	cout << "Time elapsed for Float  extreme sort: " << TimeExtremeFloat << " ms" << endl;
	clock_t TimeExtremeDouble = extreme(ArrDouble, ArrSize);
	cout << "Time elapsed for Double extreme sort: " << TimeExtremeDouble << " ms" << endl;

	//	ShowArr("\nUnsorted double array:\n", ArrDouble2, ArrSize);

	clock_t TimeMergeChar = MergeSort(ArrChar2, ArrSize);
	cout << "\nTime elapsed for Char   merge sort: " << TimeMergeChar << " ms" << endl;
	clock_t TimeMergeInt = MergeSort(ArrInt2, ArrSize);
	cout << "Time elapsed for Int    merge sort: " << TimeMergeInt << " ms" << endl;
	clock_t TimeMergeLong = MergeSort(ArrLong2, ArrSize);
	cout << "Time elapsed for Long   merge sort: " << TimeMergeLong << " ms" << endl;
	clock_t TimeMergeFloat = MergeSort(ArrFloat2, ArrSize);
	cout << "Time elapsed for Float  merge sort: " << TimeMergeFloat << " ms" << endl;
	clock_t TimeMergeDouble = MergeSort(ArrDouble2, ArrSize);
	cout << "Time elapsed for Double merge sort: " << TimeMergeDouble << " ms" << endl;

	clock_t TimeBubbleChar = bubble(ArrChar3, ArrSize);
	cout << "\nTime elapsed for Char   Bubble sort: " << TimeBubbleChar << " ms" << endl;
	clock_t TimeBubbleInt = bubble(ArrInt3, ArrSize);
	cout << "Time elapsed for Int    Bubble sort: " << TimeBubbleInt << " ms" << endl;
	clock_t TimeBubbleLong = bubble(ArrLong3, ArrSize);
	cout << "Time elapsed for Long   Bubble sort: " << TimeBubbleLong << " ms" << endl;
	clock_t TimeBubbleFloat = bubble(ArrFloat3, ArrSize);
	cout << "Time elapsed for Float  Bubble sort: " << TimeBubbleFloat << " ms" << endl;
	clock_t TimeBubbleDouble = bubble(ArrDouble3, ArrSize);
	cout << "Time elapsed for Double Bubble sort: " << TimeBubbleDouble << " ms" << endl;

	//	ShowArr("\nBubble sorted double array:\n", ArrDouble3, ArrSize);


		//ShowArr("\nSorted Int array:\n", ArrInt,ArrSize );*/

	

	for (int i = 1; i < ArrSize; i++)
	{
		ArrTreeInt[0].insert_recursive(&ArrTreeInt[i]);
	}

	//node.visit_recursive(&node);

	//TODO this pointer
	

	getchar();
	delete[] ArrTreeInt;

	delete[] ArrChar;
	delete[] ArrInt;
	delete[] ArrLong;
	delete[] ArrFloat;
	delete[] ArrDouble;
/*	delete[] ArrChar2;
	delete[] ArrInt2;
	delete[] ArrLong2;
	delete[] ArrFloat2;
	delete[] ArrDouble2;
	delete[] ArrChar3;
	delete[] ArrInt3;
	delete[] ArrLong3;
	delete[] ArrFloat3;
	delete[] ArrDouble3;

	delete[] ArrChar4;
	delete[] ArrInt4;
	delete[] ArrLong4;
	delete[] ArrFloat4;
	delete[] ArrDouble4;*/
}

template <typename T>
void ShowArr(string str, T* arr, int size)
{
	cout << "\n" << str << "  \n\n";
	for (int u = 0; u < size; u++)
		cout << arr[u] << " ";
	cout << endl;
}

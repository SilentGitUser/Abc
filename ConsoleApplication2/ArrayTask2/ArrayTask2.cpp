// ArrayTask2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;






template <typename T>
void ShowArr(string str, T* arr, int size);

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


int main()
{
	int const ArrSize = 10000;
	srand(clock());

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
	char ArrChar5[ArrSize];
	int ArrInt5[ArrSize];
	long ArrLong5[ArrSize];
	float ArrFloat5[ArrSize];
	double ArrDouble5[ArrSize];

	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i] + 0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);

	
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

		ArrChar5[i] = ArrChar[i];
		ArrInt5[i] = ArrInt[i];
		ArrLong5[i] = ArrLong[i];
		ArrFloat5[i] = ArrFloat[i];
		ArrDouble5[i] = ArrDouble[i];
	
	}

	/*cout << "ArraySize= " << ArrSize << endl;
	ShowArr("Unsorted char array:", ArrChar, ArrSize);*/
	//ShowArr("Unsorted int array:", ArrInt, ArrSize);
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

	clock_t TimeTreeInt = TreeSort(ArrInt5, ArrSize);
	cout << "Time elapsed for Int Tree sort: " << TimeTreeInt << " ms" << endl;
	clock_t TimeTreeFloat = TreeSort(ArrFloat5, ArrSize);
	cout << "Time elapsed for Float Tree sort: " << TimeTreeFloat << " ms" << endl;

	//ShowArr("\nSorted Int array:\n", ArrInt5, ArrSize);
	//	ShowArr("\nSorted Float array:\n", ArrFloat5, ArrSize);

	//cout << "\nTime elapsed to sort " << ArrSize << " int elments with Tree is " << diftime << " ms";
	//node.visit_recursive(&node);

	//TODO this pointer


	getchar();

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

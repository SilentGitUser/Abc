// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>



using namespace std;

template <class T>
clock_t bubble(T *arr, int size)
{
	T t;
	bool flag = false;
	clock_t start = clock();

	while (flag == false)
	{
		flag = true;
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = false;
			}
		}
	}
	clock_t c = clock();
	return (c - start);
}

template <class T>
clock_t MergeSort(T* arr, int size)
{
	T* t = new T[size];
	int first = 0;
	int second = 0;
	int arrnum = 0;

	clock_t start = clock();

	if (size == 1)
		return 0;

	MergeSort(arr, size / 2);
	MergeSort(arr + size / 2, size - size / 2);

	while ((first < (size / 2)) || (second < (size - size / 2)))
	{
		if (first >= (size / 2))
		{
			for (int i = second; second < (size - size / 2); i++)
			{
				t[arrnum] = *(arr + size / 2 + i);
				second++;
				arrnum++;
			}
			continue;
		}

		if (second >= (size - size / 2))
		{
			for (int i = first; i < (size / 2); i++)
			{
				t[arrnum] = *(arr + i);
				first++;
				arrnum++;
			}
			continue;
		}

		if (*(arr + first) < *(arr + size / 2 + second))
		{
			t[arrnum] = *(arr + first);
			arrnum++;
			first++;
		}
		else
		{
			t[arrnum] = *(arr + size / 2 + second);
			arrnum++;
			second++;
		}
	}

	for (int i = 0; i < size; i++)
		arr[i] = t[i];

	delete[] t;

	return clock() - start;

}


template <class T>
class Tree;

template <class T>
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

template <class T>
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

template <class T>
void Tree<T>::visit_recursive(T* SortArr)
{
	if (this->left != NULL)
		this->left->visit_recursive(SortArr);

	this->visit(SortArr);

	if (this->right != NULL)
		this->right->visit_recursive(SortArr);

}

template <class T>
void Tree<T>::visit(T *SortArr)
{
	//cout << this->k << " ";
	*(SortArr + index) = this->k;
	index++;
}



template <class T>
int Tree<T>::index = 0;


template <class T>
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

template <class T>
clock_t extreme(T *arr, int size)
{
	T t;
	clock_t start = clock();
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}

	clock_t c = clock();
	return (c - start);
}

enum SortType {ExtremeType, BubbleType, MergeType, TreeType, QuickType};

template <class T>
void SortArr(T* arr, int size, SortType type, bool print);

template <class T>
void ShowArr(string str, T* arr, int size)
{
	cout << "\n" << str << "  \n\n";
	for (int u = 0; u < size; u++)
		cout << arr[u] << " ";
	cout << endl;
}

template <class T>
void swap(T* first, T* second)
{
	T temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

template <class T>
clock_t QuickSort(T *arr, int size)
{
	clock_t starttime = clock();

	if (size <= 2) return 0;
	T pivot=arr[0];

	int i = -1;
	int j = size;

	for (;;)
	{
		do
			i++;
		while ((arr[i] < pivot) && (i<(size-2)));

		do
			j--;
		while ((arr[j] >= pivot) && (j>=1));

		//if (j == 0) break;

		if (i >= j)
		{
			QuickSort(arr, i+1);
			QuickSort(arr+i+1, size-i-1);
			break;
		}			

		swap((arr + i), (arr + j));
	}

	return clock() - starttime;
	
}

int main()
{
	 
	int const ArrSize =10;
	srand(clock());
	char ArrChar[ArrSize];
	int ArrInt[ArrSize];
	long ArrLong[ArrSize];
	float ArrFloat[ArrSize];
	double ArrDouble[ArrSize];



	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i]+0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);
	}
		
	cout << "ArraySize= " << ArrSize << endl << endl;;

	SortArr(ArrChar, ArrSize, BubbleType, false);
	SortArr(ArrInt, ArrSize, BubbleType, false);
	SortArr(ArrLong, ArrSize, BubbleType, false);
	SortArr(ArrFloat, ArrSize, BubbleType, false);
	SortArr(ArrDouble, ArrSize, BubbleType, false);

	cout << endl;

	SortArr(ArrChar, ArrSize, ExtremeType, false);
	SortArr(ArrInt, ArrSize, ExtremeType, false);
	SortArr(ArrLong, ArrSize, ExtremeType, false);
	SortArr(ArrFloat, ArrSize, ExtremeType, false);
	SortArr(ArrDouble, ArrSize, ExtremeType, false);

	cout << endl;

	SortArr(ArrChar, ArrSize, MergeType, false);
	SortArr(ArrInt, ArrSize, MergeType, false);
	SortArr(ArrLong, ArrSize, MergeType, false);
	SortArr(ArrFloat, ArrSize, MergeType, false);
	SortArr(ArrDouble, ArrSize, MergeType, false);

	cout << endl;

	SortArr(ArrChar, ArrSize, TreeType, false);
	SortArr(ArrInt, ArrSize, TreeType, false);
	SortArr(ArrLong, ArrSize, TreeType, false);
	SortArr(ArrFloat, ArrSize, TreeType, false);
	SortArr(ArrDouble, ArrSize, TreeType, false);

	cout << endl;

	//SortArr(ArrChar, ArrSize, QuickType, false);
	SortArr(ArrInt, ArrSize, QuickType, true);
	SortArr(ArrLong, ArrSize, QuickType, false);
	SortArr(ArrFloat, ArrSize, QuickType, false);
	SortArr(ArrDouble, ArrSize, QuickType, false);


	/*ShowArr("Unsorted char array:", ArrChar, ArrSize);
	ShowArr("Unsorted int array:", ArrInt, ArrSize);
	ShowArr("Unsorted long array:", ArrLong, ArrSize);
	ShowArr("Unsorted float array:", ArrFloat, ArrSize);
	ShowArr("Unsorted double array:", ArrDouble, ArrSize);*/

	//SortArr(ArrChar, ArrSize, BubbleType, true);

/*	clock_t TimeExtremeChar=extreme(ArrChar, ArrSize);
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

	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i] + 0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);
	}

	clock_t TimeMergeChar = MergeSort(ArrChar, ArrSize);
	cout << "\nTime elapsed for Char   merge sort: " << TimeMergeChar << " ms" << endl;
	clock_t TimeMergeInt = MergeSort(ArrInt, ArrSize);
	cout << "Time elapsed for Int    merge sort: " << TimeMergeInt << " ms" << endl;
	clock_t TimeMergeLong = MergeSort(ArrLong, ArrSize);
	cout << "Time elapsed for Long   merge sort: " << TimeMergeLong << " ms" << endl;
	clock_t TimeMergeFloat = MergeSort(ArrFloat, ArrSize);
	cout << "Time elapsed for Float  merge sort: " << TimeMergeFloat << " ms" << endl;
	clock_t TimeMergeDouble = MergeSort(ArrDouble, ArrSize);
	cout << "Time elapsed for Double merge sort: " << TimeMergeDouble << " ms" << endl;

	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i] + 0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);
	}

	clock_t TimeBubbleChar = bubble(ArrChar, ArrSize);
	cout << "\nTime elapsed for Char   Bubble sort: " << TimeBubbleChar << " ms" << endl;
	clock_t TimeBubbleInt = bubble(ArrInt, ArrSize);
	cout << "Time elapsed for Int    Bubble sort: " << TimeBubbleInt << " ms" << endl;
	clock_t TimeBubbleLong = bubble(ArrLong, ArrSize);
	cout << "Time elapsed for Long   Bubble sort: " << TimeBubbleLong << " ms" << endl;
	clock_t TimeBubbleFloat = bubble(ArrFloat, ArrSize);
	cout << "Time elapsed for Float  Bubble sort: " << TimeBubbleFloat << " ms" << endl;
	clock_t TimeBubbleDouble = bubble(ArrDouble, ArrSize);
	cout << "Time elapsed for Double Bubble sort: " << TimeBubbleDouble << " ms" << endl;

	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i] + 0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);
	}

	clock_t TimeTreeChar = TreeSort(ArrChar, ArrSize);
	cout << "\nTime elapsed for Char   Tree sort: " << TimeTreeChar << " ms" << endl;
	clock_t TimeTreeInt = TreeSort(ArrInt, ArrSize);
	cout << "Time elapsed for Int    Tree sort: " << TimeTreeInt << " ms" << endl;
	clock_t TimeTreeLong = TreeSort(ArrLong, ArrSize);
	cout << "Time elapsed for Long   Tree sort: " << TimeTreeLong << " ms" << endl;
	clock_t TimeTreeFloat = TreeSort(ArrFloat, ArrSize);
	cout << "Time elapsed for Float  Tree sort: " << TimeTreeFloat << " ms" << endl;
	clock_t TimeTreeDouble = TreeSort(ArrDouble, ArrSize);
	cout << "Time elapsed for Double Tree sort: " << TimeTreeDouble << " ms" << endl;


	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i] + 0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);
	}

	clock_t TimeQuickChar = QuickSort(ArrChar, ArrSize);
	cout << "\nTime elapsed for Char   Quick sort: " << TimeQuickChar << " ms" << endl;
	clock_t TimeQuickInt = QuickSort(ArrInt, ArrSize);
	cout << "Time elapsed for Int    Quick sort: " << TimeQuickInt << " ms" << endl;
	clock_t TimeQuickLong = QuickSort(ArrLong, ArrSize);
	cout << "Time elapsed for Long   Quick sort: " << TimeQuickLong << " ms" << endl;
	clock_t TimeQuickFloat = QuickSort(ArrFloat, ArrSize);
	cout << "Time elapsed for Float  Quick sort: " << TimeQuickFloat << " ms" << endl;
	clock_t TimeQuickDouble = QuickSort(ArrDouble, ArrSize);
	cout << "Time elapsed for Double Quick sort: " << TimeQuickDouble << " ms" << endl;


//	ShowArr("\nTree sorted double array:\n", ArrDouble3, ArrSize);


	//ShowArr("\nSorted Int array:\n", ArrInt,ArrSize );*/

	getchar();

}


template <class T>
void SortArr(T* arr, int size, SortType type, bool print)
{
	T* arrTemp = new T[size];
	clock_t res;
	for (int i = 0; i < size; i++)
		arrTemp[i] = *(arr + i);

	if (print)
		ShowArr("Unsorted array: ", arrTemp, size);


	switch (type)
	{
		case SortType::BubbleType:
	{
		res = bubble<T>(arrTemp, size);
		cout << "Time elapsed for " << typeid(arrTemp).name() << " bubble sort: " << res << " ms" << endl;
		break;
	}
		case SortType::MergeType:
	{
		res = MergeSort<T>(arrTemp, size);
		cout << "Time elapsed for " << typeid(arrTemp).name() << " merge sort: " << res << " ms" << endl;
		break; 
	}
		case ExtremeType:
	{
		res = extreme<T>(arrTemp, size);
		cout << "Time elapsed for " << typeid(arrTemp).name() << " extreme sort: " << res << " ms" << endl;
		break;
	}

		case TreeType:
	{
		res = TreeSort<T>(arrTemp, size);
		cout << "Time elapsed for " << typeid(arrTemp).name() << " tree sort: " << res << " ms" << endl;
		break;
	}
		case QuickType:
	{
		res = QuickSort<T>(arrTemp, size);
		cout << "Time elapsed for " << typeid(arrTemp).name() << " quick sort: " << res << " ms" << endl;
		break;
	}
}

	if (print)
		ShowArr("Sorted array: ", arrTemp, size);
				
delete[] arrTemp;

}



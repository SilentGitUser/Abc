// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>



using namespace std;

template <typename T>
clock_t bubble(T *arr, int size);

template <typename T>
void ShowArr(string str, T* arr, int size);

template <typename T>
clock_t MergeSort(T* arr, int size);

int main()
{
	 
	int const ArrSize =5000;
	srand(300);
	char* ArrChar = new char[ArrSize];
	int* ArrInt=new int[ArrSize];
	long* ArrLong = new long[ArrSize];
	float* ArrFloat = new float[ArrSize];
	double* ArrDouble = new double[ArrSize];
	char* ArrChar2 = new char[ArrSize];
	int* ArrInt2 = new int[ArrSize];
	long* ArrLong2 = new long[ArrSize];
	float* ArrFloat2 = new float[ArrSize];
	double* ArrDouble2 = new double[ArrSize];


	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i]+0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);

		ArrChar2[i] = ArrChar[i];
		ArrInt2[i] = ArrInt[i];
		ArrLong2[i] = ArrLong[i];
		ArrFloat2[i] = ArrFloat[i];
		ArrDouble2[i] = ArrDouble[i];
	}
		
	cout << "ArraySize= " << ArrSize << endl;
	/*ShowArr("Unsorted char array:", ArrChar, ArrSize);
	ShowArr("Unsorted int array:", ArrInt, ArrSize);
	ShowArr("Unsorted long array:", ArrLong, ArrSize);
	ShowArr("Unsorted float array:", ArrFloat, ArrSize);
	ShowArr("Unsorted double array:", ArrDouble, ArrSize);*/

	clock_t TimeBubbleChar=bubble(ArrChar, ArrSize);
	cout << "\nTime elapsed for Char   bubble sort: " << TimeBubbleChar << " ms" << endl;
	clock_t TimeBubbleLong = bubble(ArrLong, ArrSize);
	cout << "Time elapsed for Long   bubble sort: " << TimeBubbleLong << " ms" << endl;
	clock_t TimeBubbleInt = bubble(ArrInt, ArrSize);
	cout << "Time elapsed for Int    bubble sort: " << TimeBubbleInt << " ms" << endl;
	clock_t TimeBubbleFloat = bubble(ArrFloat, ArrSize);
	cout << "Time elapsed for Float  bubble sort: " << TimeBubbleFloat << " ms" << endl;
	clock_t TimeBubbleDouble = bubble(ArrDouble, ArrSize);
	cout << "Time elapsed for Double bubble sort: " << TimeBubbleDouble << " ms" << endl;

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

//	ShowArr("\nMerge sorted double array:\n", ArrDouble2, ArrSize);


	//ShowArr("\nSorted Int array:\n", ArrInt,ArrSize );

	getchar();

	delete[] ArrChar;
	delete[] ArrInt;
	delete[] ArrLong;
	delete[] ArrFloat;
	delete[] ArrDouble;
	delete[] ArrChar2;
	delete[] ArrInt2;
	delete[] ArrLong2;
	delete[] ArrFloat2;
	delete[] ArrDouble2;


}

template <typename T>
clock_t bubble(T *arr, int size)
{
	T t;
	clock_t start= clock();
	for (int i = 0; i < size; i++)
		for (int j =i; j<size; j++)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}

	clock_t c = clock();
	return (c-start);
}

template <typename T>
void ShowArr(string str,T* arr, int size)
{
	cout << "\n" << str << "  \n\n";
	for (int u = 0; u < size; u++)
		cout << arr[u] << " ";
	cout << endl;
}

template <typename T> 
clock_t MergeSort(T* arr, int size)
{
	T* t=new T[size];
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
			t[arrnum] = *(arr + size/2+second);
			arrnum++;
			second++;
		}
	}
	
	for (int i = 0; i < size; i++)
			arr[i] = t[i];

	delete[] t;

	return clock() - start;

}

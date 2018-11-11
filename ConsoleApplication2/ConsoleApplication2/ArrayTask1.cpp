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

int main()
{
	 
	int const ArrSize =10000;
	srand(300);
	char* ArrChar = new char[ArrSize];
	int* ArrInt=new int[ArrSize];
	long* ArrLong = new long[ArrSize];
	float* ArrFloat = new float[ArrSize];
	double* ArrDouble = new double[ArrSize];


	for (int i = 0; i < ArrSize; i++)
	{
		ArrInt[i] = rand();
		ArrFloat[i] = (float)ArrInt[i]+0.5;
		ArrDouble[i] = ArrFloat[i] * 3;
		ArrLong[i] = (long)ArrDouble[i];
		ArrChar[i] = (char)(ArrInt[i] / 128);
	}
		
	cout << "ArraySize= " << ArrSize << endl;
	/*ShowArr("Unsorted char array:", ArrChar, ArrSize);
	ShowArr("Unsorted int array:", ArrInt, ArrSize);
	ShowArr("Unsorted long array:", ArrLong, ArrSize);
	ShowArr("Unsorted float array:", ArrFloat, ArrSize);
	ShowArr("Unsorted double array:", ArrDouble, ArrSize);*/

	clock_t TimeBubbleChar=bubble(ArrChar, ArrSize);
	cout << "Time elapsed for Char bubble sort: " << TimeBubbleChar << " ms" << endl;
	clock_t TimeBubbleLong = bubble(ArrLong, ArrSize);
	cout << "Time elapsed for Long bubble sort: " << TimeBubbleLong << " ms" << endl;
	clock_t TimeBubbleInt = bubble(ArrInt, ArrSize);
	cout << "Time elapsed for Int bubble sort: " << TimeBubbleInt << " ms" << endl;
	clock_t TimeBubbleFloat = bubble(ArrFloat, ArrSize);
	cout << "Time elapsed for Float bubble sort: " << TimeBubbleFloat << " ms" << endl;
	clock_t TimeBubbleDouble = bubble(ArrDouble, ArrSize);
	cout << "Time elapsed for Double bubble sort: " << TimeBubbleDouble << " ms" << endl;

	//ShowArr("\nSorted Int array:\n", ArrInt,ArrSize );

	getchar();

	delete[] ArrChar;
	delete[] ArrInt;
	delete[] ArrLong;
	delete[] ArrFloat;
	delete[] ArrDouble;


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
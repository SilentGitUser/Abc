// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>


using namespace std;

clock_t bubble(int *arr, int size);

int main()
{
    cout << "Unsorted array:\n"; 
	int const ArrSize =20;
	srand(300);
	int* arr1=new int[ArrSize];

	for (int i = 0; i < ArrSize; i++)
		arr1[i] = rand();
	cout << endl;
	for (int i = 0; i < ArrSize; i++)
		cout<<arr1[i]<<" ";

	clock_t time_bubble=bubble(arr1, ArrSize);



	cout << endl<<"\nSorted array:\n\n";
	for (int i = 0; i < ArrSize; i++)
		cout<<arr1[i]<<" ";

	cout << endl << time_bubble << endl << endl;
	getchar();

	delete[] arr1;

}

clock_t bubble(int *arr, int size)
{
	int t;
	clock_t start= clock();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}

	clock_t c = clock();
	return (c-start);
}

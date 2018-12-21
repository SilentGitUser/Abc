#include "pch.h"
#include <ctime>
#include "extreme.h"

template <typename T>
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
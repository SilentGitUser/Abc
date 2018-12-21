#include "pch.h"
#include "Merge.h"

template <typename T>
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
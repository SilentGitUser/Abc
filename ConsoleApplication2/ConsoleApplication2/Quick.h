#pragma once
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

template <class T>
void swap(T* first, T* second);

template <class T>
clock_t QuickSort(T *arr, int size);
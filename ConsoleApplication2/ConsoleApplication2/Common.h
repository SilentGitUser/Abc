#pragma once

#include <string>
#include <iostream>

using namespace std;

template <typename T>
void ShowArr(string str, T* arr, int size);

enum SortType { BubbleType, MergeType, ExtremeType, TreeType } ;
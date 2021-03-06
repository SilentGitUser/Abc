// VectorTry513.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	setlocale(LC_ALL, "ru-RU");
	vector<char> v(10);
	vector <char> v2;
	char str[] = "<Vector>";
	int i;

	for (i = 0; i < 10; i++) v[i] = i + 'a';

	for (i = 0; str[i]; i++) v2.push_back(str[i]);

	cout << "Исходное содержание вектора v:\n";
	for (i = 0; i < v.size(); i++)cout << v[i] << " ";
	cout << endl << endl;

	vector<char>::iterator p = v.begin();
	p += 2;

	v.insert(p, 10, 'X');

	cout << "РАзмер веткора после вставки символов 'X' ="
		<< v.size() << endl;
	cout << "Содержимое вектора v после вставки символов:\n";
	for (i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	p = v.begin();
	p += 2;
	v.erase(p, p + 10);

	cout << "Размер вектора v после удаления = " << v.size() << endl;

	cout << "Содержание вектора v после удаления:\n";
	for (i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl<<endl;

	//if I don't re assign the iterator p, the compiler says that iterator is out of range
	//but the value of iterator p in WATCH window is the same
	p = v.begin();
	p += 2;
	v.insert(p, v2.begin(), v2.end());
	cout << "Размер ветора v после вставки вектора v2 = ";
	cout << v.size() << endl;
	cout << "Содержимое веткора v после вставки:\n";
	for (i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n";

	getchar();
	return 0;
	
}
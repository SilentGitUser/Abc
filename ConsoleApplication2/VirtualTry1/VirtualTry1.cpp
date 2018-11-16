// VirtualTry1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class base
{
public:
	int i;
	virtual void show() = 0;
	//{
	//	cout << "Функция класса base \n";
	//};

};

class der1 : public base
{
	 void show()
	{
		cout << "Функция класса der1 \n";
	}
};

class der2 : public base
{
	 void show()
	{
		cout << "Функция класса der2 \n";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	base *p;
	der1 d1;
	der2 d2;

//	b = new base();
	//p = &b;
//	d1 = new der1();
//	d2 = new der2();

//	p->show();

	p = &d1;
	p->show();

	p = &d2;
	p->show();

//	delete b;
//	delete d1;
//	delete d2;

  //  std::cout << "Hello World!\n"; 
	getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// ArrayTask2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//class Tree;

class Tree
{
	Tree* left;
	Tree* right;
	Tree* root;
	int k;
public:
	void insert(Tree aTree);
	void insert_recursive(Tree root_node, Tree node_to_insert);
	void visit();
	void visit_recursive();	
};

void Tree::insert(Tree node)
{
	//if (node->root == NULL)


}

int main()
{
	const int ArrSize = 10;
    std::cout << "Hello World!\n"; 
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

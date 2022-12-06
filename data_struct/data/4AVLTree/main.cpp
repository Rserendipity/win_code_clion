#include <iostream>
#include "AVLTree.h"

using namespace std;

void test1()
{
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	AVLTree<int> tree;

	for (auto n : arr)
	{
		tree.insert(n);
	}
}

void test2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	AVLTree<int> tree;

	for (auto n : arr)
	{
		tree.insert(n);
	}
	
}

int main()
{
	// test1();
	test2();
	return 0;
}

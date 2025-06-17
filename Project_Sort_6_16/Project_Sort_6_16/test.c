#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"sort.h"

void TestInsertSort() 
{
	int test[10] = { 1,3,5,7,9,2,4,6,8,0 };
	Insert_Sort(test, 10);
	PrintArray(test, sizeof(test) / sizeof(test[0]));
}

void TestHeapSort()
{
	int test[10] = { 1,3,5,7,9,2,4,6,8,0 };
	Heap_Sort(test, 10);
	PrintArray(test, sizeof(test) / sizeof(test[0]));
}

void TestBubbleSort()
{
	int test[10] = { 1,3,5,7,9,2,4,6,8,0 };
	Bubble_Sort(test, 10);
	PrintArray(test, sizeof(test) / sizeof(test[0]));
}

void TestShellSort()
{
	int test[10] = { 1,3,5,7,9,2,4,6,8,0 };
	Shell_Sort(test, 10);
	PrintArray(test, sizeof(test) / sizeof(test[0]));
}

void TestSelectSort()
{
	int test[] = {9,1,2,5,7,4,6,3 };
	Select_Sort(test, sizeof(test) / sizeof(test[0]));
	PrintArray(test, sizeof(test) / sizeof(test[0]));
}

void TestQuickSort()
{
	int test[] = { 9,1,2,5,7,4,6,3 };
	Select_Sort(test, sizeof(test) / sizeof(test[0]));
	PrintArray(test, sizeof(test) / sizeof(test[0]));
}
int main() 
{
	//TestInsertSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestShellSort();
	//TestSelectSort();
	TestQuickSort();


	return 0;
}
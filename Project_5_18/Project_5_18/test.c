#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
// self-try(wrong)
//void bubble_sort(int* array, int sz)
//{
//	int count = 0;
//	do
//		for (int i = 0; i < sz-1;i++)
//		{
//			if(array[i] > array[i+1])
//			{
//				int n = array[i];
//				array[i] = array[i+1];
//				array[i + 1] = n;
//				count++;
//			}
//		}
//	while (count != 0);
//}
//int main() 
//{
//	int array[10] = { 0,8,6,2,9,7,5,1,3,4 };
//	int sz = sizeof(array) / sizeof(array[0]);
//	bubble_sort(array, sz);
//
//	for (int i = 0;i < sz;i++) 
//	{
//		printf("%d ", array[i]);
//	}
//
//	return 0;
//}


////bubble sort (from small to large)
//#include<stdio.h>
//void bubble_sort(int* array, int sz) 
//{
//	for (int i = 0;i < sz;i++)
//	{
//		for (int j = 0; j < sz - i - 1;j++) 
//		{
//			if (array[j] > array[j + 1])
//			{
//				int tmp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = tmp;
//			}
//
//		}
//	}
//}
//
//void print_arr(int* arr, int sz) 
//{
//	for (int i = 0;i < sz; i++) 
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main() 
//{
//	int array[10] = { 2,3,6,7,8,9,1,4,5,0 };
//	int sz = sizeof(array) / sizeof(array[0]);
//	bubble_sort(array, sz);
//	print_arr(array, sz);
//	return 0;
//}


#include<stdio.h>
void print(int(*arr)[5], int m, int n)
{
	for (int i = 0;i < m;i++) 
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}

}
int main()
{
	int array[3][5] = { {1,2,3,4,5},{2,3,4,5,6}, { 3,4,5,6,7 } };
	print(array, 3, 5);
	return 0;
}
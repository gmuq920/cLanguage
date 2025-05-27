#define _CRT_SECURE_NO_WARNINGS

////Change two ints' position
//#include <stdio.h>
//void change(int* x, int* y) 
//{
//	int z = *x;
//	 *x = *y;
//	*y = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d %d\n", a, b);
//	change(&a, &b);
//	printf("%d %d\n", a, b);
//
//
//	return 0;
//}

#include<stdio.h>
int main()
{
	int array[10] = { 0 };
	int sz = sizeof(array) / sizeof(array[0]);
	
	for (int i = 0;i < sz; i++)
	{
		scanf("%d", array + i);
	}

	for (int i = 0;i < sz;i++) 
	{
		printf("%d ", *(array+i));

	}

	return 0;
}

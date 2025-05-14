#define _CRT_SECURE_NO_WARNINGS

//Tower pf Hanoi
//The Tower of Hanoi is a mathematical puzzle where you have three rods and a number of disks of different sizes.The objective is to move the entire stack to another rod, obeying the following rules :
//
//1.Only one disk may be moved at a time.
//
//2.Each move consists of taking the top disk from one of the stacks and placing it on top of another stack or on an empty rod.
//
//3.No larger disk may be placed on top of a smaller disk.
//
//#include<stdio.h>
//int Hanoi(int n) 
//{
//	if (1 == n)
//	{
//		return 1;
//	}
//	
//	else if (n >= 2) 
//	{
//		return Hanoi(n - 1) * 2 + 1;
//	}
//	
//}
//int main() 
//{
//	int input = 0;
//	printf("Input the number of the disk:");
//	scanf("%d", &input);
//	printf("%d", Hanoi(input));
//
//
//	return 0;
//
//}

#include <stdio.h>

int main()
{
	int m = 0;
	int n = 0;
	printf("Input two integers:");
	scanf("%d""%d", &m, &n);
	int dif = m ^ n;
	int count = 0;
	while (dif)
	{
		dif = dif & (dif - 1);
		count++;
	}
	printf("%d", count);
	return 0;
}
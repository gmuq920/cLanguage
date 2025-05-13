#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
////use iteration to solve n's factorial
//int factorial(int n) 
//{
//	int final = 1;
//	for (int i = 1; i <= n; i++) 
//	{
//		final *= n;
//	}
//	return final;
//
//}
//int main()
//{
//	int n = 0;
//	printf("%d",factorial(n));
//
//	return 0;
//}

////get Fibonacci num(recursion)
//#include<stdio.h>
//
//int fibonacci(int n)
//{
//	if (1 == n || 2 == n)
//	{
//		return 1;
//	}
//	else 
//	{
//		return fibonacci(n - 1) + fibonacci(n - 2);
//	}
//	
//}
//int main()
//{
//	int input = 0;
//	printf("input a integer: ");
//	scanf("%d", &input);
//	printf("%d",fibonacci(input));
//
//	return 0;
//}

////get fibonacci num(iteration)
//#include<stdio.h>
//int fibonacci(int n)
//{
//	int num1 = 1;
//	int num2 = 1;
//	int num3 = 1;
//	for (int i = 3; i <= n;i++) 
//	{
//		num3 = num1;
//		num1 = num2;
//		num2 = num3 + num2;
//	}
//	return num2;
//}
//int main()
//{
//	
//	int input = 0;
//	printf("input a interger:");
//	scanf("%d", &input);
//	printf("%d", fibonacci(input));
//	return 0;
//}

//

#define _CRT_SECURE_NO_WARNINGS

////factorial use recursion
//#include<stdio.h>
//
//int factorial(int n) 
//{
//	if (0 == n) {
//		return 1;
//	}
//	else
//		return factorial(n - 1) * n;
//}
//int main(){
//	int n = 0;
//	printf("请输入一个整数：");
//	scanf("%d", &n);
//	printf("%d",factorial(n));
//	
//	return 0;
//}

//Input a number, and separate it to each of single number;
#include<stdio.h>
void getNum(int num)
{
	if (num < 10) {
		printf("%d ", num);
	}
	else if (num >= 10)
	{
		getNum(num/10);
		printf("%d ", (num % 10));
	}
}
	
int main() 
{
	int num = 0;
	printf("input a set of numbers: ");
	scanf("%d", &num);
	getNum(num);
	return 0;
}
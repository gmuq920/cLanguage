#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() 
{
	//int a = 20;
	//int* pa = &a;
	//printf("%p\n", pa); 
	//printf("Size of pa is %zd\n", sizeof(pa)); //Size of the pointer only depends on the bit version of system
	//pa += 1;
	//printf("%p\n", pa);//pa+4 because the size of int is 4

	//char* pb = &a;
	//printf("%p\n", pb);//get the same pointer with int*
	//pb += 1;
	//printf("%p\n", pb);//only plus one because the size of char is one
	

	int a = 10;
	int* p = &a;
	printf("%zd", &p);
	return 0;
}
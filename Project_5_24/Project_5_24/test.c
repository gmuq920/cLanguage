#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a = 4;
//	float b = 5.5;
//	double c = 5.0;
//	float* pb = &b;
//
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(b));
//	printf("%d\n", sizeof(c));
//	printf("%p", pb);
//
//	return 0;
//}

////Try to use union to design the program
//struct gift_list
//{
//    int stock_num;
//	int price;
//	int item_type;
//	union 
//	{
//		struct 
//		{
//			char book_name[20];
//			int page_num;
//			char author[20];
//		}book;
//		
//		struct
//		{
//			char design[20];
//		}cup;
//
//		struct
//		{
//			int color;
//			char design[20];
//			int size;
//		}shirt;
//	}item;
//
//};

////Big endian OR Little 

//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int* pa = &a;
//	if (*(char*)pa)
//	{
//		printf("Little endian");
//	}
//	else
//		printf("Big endian");
//	return 0;
//}


//#include <stdio.h>
//union un
//{
//	char i;
//	int a;
//};
//int main() 
//{
//	union un un;
//	un.a = 1;
//	if (un.i)
//	{
//		printf("Little endian");
//	}
//	else
//		("Big endian");
//	return 0;
//}

#include<stdlib.h>
#include <stdio.h>

//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	for (int i = 0; i < 10;i++) 
//	{
//		*p = i + 1;
//	}
//
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(INT_MAX);
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	for (int i = 0; i < 10;i++)
	{
		*p = i + 1;
	}

	return 0;
}
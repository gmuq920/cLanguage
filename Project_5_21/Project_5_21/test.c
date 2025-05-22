#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//#include<ctype.h>
//int main()
//{
//	int ret = islower('o');
//	printf("%d", ret);
//	return 0;
//}

//#include<ctype.h>
//int main()
//{
//	char str[] = "Student";
//	int sz = sizeof(str) / sizeof(str[0]);
//	for (int i = 0;i < sz;i++) 
//	{
//		if (islower(str[i])!= 0) 
//		{
//			str[i] -= 32;
//		}
//	}
//
//	printf("%s", str);
//
//	return 0;
//}

#include<ctype.h>
int main()
{
	char str[] = "Student";
	int sz = sizeof(str) / sizeof(str[0]);
	for (int i = 0;i < sz;i++) 
	{
		str[i] = toupper(str[i]);
	}
	printf("%s", str);
	return 0;
}

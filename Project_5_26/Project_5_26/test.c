#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


////use stream to read and write;
//int main() 
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL) 
//	{
//		perror(fopen);
//		return 1;
//	}
//	for (int i = 'a';i <= 'z'; i++) 
//	{
//		fputc(i, pf);
//	}
//
//	fclose(pf);
//
//	FILE* pfRead = fopen("data.txt", "r");
//	if (pfRead == NULL)
//	{
//		perror(fopen);
//		return 1;
//	}
//	int output = 0;
//	while ((output = fgetc(pfRead)) != EOF)
//	{
//		printf("%c ", output);
//	}
//	return 0;
//}
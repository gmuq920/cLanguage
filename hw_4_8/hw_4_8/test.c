#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	printf("请输入2-20之内的整数：");
//	scanf("%d", &num);
//	for (int i = 0;i < num;i++)
//	{
//		for (int j = 0;j < num;j++)
//		{
//			if (i == j || (i + j) == num - 1)
//			{
//				printf("%c",'*');
//			}
//			else
//				printf("%c", ' ');
//			
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}

//#include<stdio.h>

//int main() 
//{
//	int num = 0;
//	printf("请输入2-20的一个整数：");
//	scanf("%d", &num);
//	for (int i = 0;i < num; i++) 
//	{
//		for (int j = 0;j < num;j++) 
//		{
//			if ((i == 0) || (i == num-1))
//			{
//				printf("%s","* ");
//			}
//			else 
//			{
//				if ((0==j) || (j == num - 1))
//				{
//					printf("%s","* ");
//
//				}
//				else
//					printf("%s", "  ");
//			}
//		}
//		printf("\n");
//
//	}
//	
//}


//#include <stdio.h>
//int main()
//{
//	int matrix[10][10];
//	int row = 0;
//	int col = 0;
//	printf("请输入行列数：");
//	scanf("%d""%d",&row,&col);
//	
//	for (int i = 0; i < row;i++) 
//	{
//		for (int j = 0;j < col;j++) 
//		{
//			printf("请依次输入二维数组内容：");
//			scanf("%d", &matrix[i][j]);
//			
//		}
//	}
//
//	for (int i = 0;i < col;i++)
//	{
//		for (int j = 0;j < row;j++) 
//		{
//			printf("%d ", matrix[j][i]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//#include <stdio.h>
//int main() 
//{
//	int array[10];
//	
//	for (int i = 0;i < 10;i++) 
//	{
//		printf("请输入第%d个数字:",i+1);
//		scanf("%d", &array[i]);
//	}
//	for (int j = 9;j >= 0;j--) 
//	{
//		printf("%d ",array[j]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main() 
//{
//	int finalPosition = 0;
//	int array1[1000];
//	int array2[1000];
//	int array3[3000];
//	int array1Len = 0;
//	int array2Len = 0;
//	printf("请输入两个array的长度：");
//	scanf("%d""%d", &array1Len, &array2Len);
//	printf("请输入第一个数组的数字：");
//	for (int i = 0;i < array1Len;i++)
//	{
//		scanf("%d", &array1[i]);
//	}
//	printf("请输入第二个数组的数字：");
//	for (int i = 0;i < array2Len;i++)
//	{
//		scanf("%d", &array2[i]);
//	}
//
//	int test1 = 0;
//	int test2 = 0;
//
//	while (test1 < array1Len && test2 < array2Len)
//	{
//		if (array1[test1] < array2[test2]) 
//		{
//			array3[finalPosition] = array1[test1];
//			test1++;
//			finalPosition++;
//		}
//		else if (array1[test1] > array2[test2])
//		{
//			array3[finalPosition] = array2[test2];
//			test2++;
//			finalPosition++;
//		}
//		else 
//		{
//			array3[finalPosition] = array1[test1];
//			array3[finalPosition + 1] = array1[test1];
//			test1++;
//			test2++;
//			finalPosition = finalPosition + 2;
//		}
//	}
//
//	if (test1  == array1Len) 
//	{
//		for (int i = test2;i < array2Len;i++) 
//		{
//			array3[finalPosition] = array2[i];
//			finalPosition++;
//		}
//	}
//	else 
//	{
//		for (int i = test1;i < array1Len;i++)
//		{
//			array3[finalPosition] = array1[i];
//			finalPosition++;
//		}
//
//	}
//	
//	for (int i = 0;i < finalPosition;i++)
//	{
//		printf("%d ", array3[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int array[10];
//	printf("输入十个整数：");
//	int sum = 0;
//	int input = 0;
//	for (int i = 0; i < 10;i++) 
//	{
//		scanf("%d", &input);
//		array[i] = input;
//		sum += input;
//	}
//
//	double avg = sum / 10.0;
//	printf("%lf", avg);
//
//	return 0;
//}


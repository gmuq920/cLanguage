#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	//开辟
//	int** p = (int**)malloc(3 * sizeof(int*));
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		p[i] = (int*)malloc(5 * sizeof(int));
//	}
//	//使用
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			p[i][j] = 5 * i + j;
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	for (i = 0; i < 3; i++)
//	{
//		free(p[i]);
//	}
//	free(p);
//	p = NULL;
//
//
//	return 0;
//}


int check_sys()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}

int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

//int* getConcatenation(int* nums, int numsSize, int* returnSize) {
//	//定义一个长度为nums数组长度两倍的数组ans
//	int* ans = malloc(2 * numsSize * sizeof(int));
//	int i = 0;
//	//遍历nums数组，将下标为x的元素分别赋值给ans数组中下标为x和下标为x+m的元素；
//	for (i = 0; i < numsSize; i++) {
//		ans[i] = nums[i];
//		ans[i + numsSize] = nums[i];
//	}
//	//更新数组长度并返回数组
//	*returnSize = 2 * numsSize;
//	return ans;
//}
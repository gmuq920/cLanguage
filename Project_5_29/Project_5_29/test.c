#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	//����
//	int** p = (int**)malloc(3 * sizeof(int*));
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		p[i] = (int*)malloc(5 * sizeof(int));
//	}
//	//ʹ��
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
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}

//int* getConcatenation(int* nums, int numsSize, int* returnSize) {
//	//����һ������Ϊnums���鳤������������ans
//	int* ans = malloc(2 * numsSize * sizeof(int));
//	int i = 0;
//	//����nums���飬���±�Ϊx��Ԫ�طֱ�ֵ��ans�������±�Ϊx���±�Ϊx+m��Ԫ�أ�
//	for (i = 0; i < numsSize; i++) {
//		ans[i] = nums[i];
//		ans[i + numsSize] = nums[i];
//	}
//	//�������鳤�Ȳ���������
//	*returnSize = 2 * numsSize;
//	return ans;
//}
#define _CRT_SECURE_NO_WARNINGS


////�����鳤��
//#include<stdio.h>
//int main() {
//	int arr[] = { 1,2,3,4,5,6 };
//	printf("%d\n", sizeof(arr));
//	int length = sizeof(arr) / sizeof(arr[0]);
//	printf("%d",length);
//	return 0;
//}


////���м��£
//#include <stdio.h>
//#include<stdlib.h>
//#include<windows.h>
//int main()
//{
//	char array[] = "HELLO WORLD!!!";
//	char arrayNew[20] = { 0 };
//	int length = strlen(array);
//	for (int i = 0; i < length/2 ;i++)
//	{
//		//��ȷ����ǰ���������Լ���Ҫprint��array����
//		arrayNew[i] = array[i];
//		arrayNew[length - i -1] = array[length - i - 1];
//		for (int j = i + 1;j <= (length - i)-2;j++)
//		{
//			arrayNew[j] = '*';
//		}
//
//		//print arrayNew�е���ֵ
//		for (int k = 0; k < length ;k++) 
//		{
//			printf("%c", arrayNew[k]); 
//		}
//
//		printf("\n");
//		Sleep(1000); //sleep������λΪms����Windows��ʹ�ã�ͷ�ļ�Ϊwindows.h)
//		system("cls");
//	}
//	printf("%s", array);
//		return 0;
//}
//

//���ֲ���
#include <stdio.h>
int binarySearch(int i, int array[],int length) 
{
	int bool = 1;
	int test = length / 2;
	int high = length;
	int low = 0;
	while (1) 
	{
		if (low > high) {
			return -1;
		}
		else {
			if (array[test] > i)
			{
				high = test - 1;
				test = (high + low) / 2;

			}
			else if (array[test] < i)
			{
				low = test + 1;
				test = (high + low) / 2;
			}

			else
			{
				bool = 0;
				return test;
			}
		}
	}		
}

int main() 
{
	int numbers[] = { 1,2,3,4,5,6,7,8,9,10 };
	int length = sizeof(numbers) / sizeof(numbers[0]);
	int k = 0;

	printf("����ʮ����������");
	scanf("%d", &k);
	int final = binarySearch(k, numbers,length);
	if (-1 == final) 
	{
		printf("������û���������");
	}
	else
		printf("�����������еĵ�%dλ", final);
	
	return 0;
}
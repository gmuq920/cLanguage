#define _CRT_SECURE_NO_WARNINGS



////try goto �����������루����������ȷ��ֹ������
//
//#include <string.h>
//#include<stdlib.h>
//#include<stdio.h>
//
//int main() 
//{
//	char kb[20] = { 0 };
//	system("shutdown -s -t 60");
//	printf("���Խ�����60s��ػ�����������ȷ��������ֹͣ��\n");
//	printf("��������Ϊ��");
//again:
//
//	scanf("%s", kb);
//	if (strcmp(kb, "750219") == 0)
//	{
//		system("shutdown -a");
//		printf("������ȷ���ػ������ѱ�ȡ����");
//	}
//
//	else
//	{
//		printf("����������ٴ����룺");
//		goto again;
//	}
//		
//
//
//	return 0;
//
//}

//Set up a game to guess a random number 

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
	srand((unsigned int)time(NULL));
	printf("��ӭ�����������Ϸ�����ַ�ΧΪ0-100��\n");
restart:

	
	int guess = rand() % 100 + 1;
	int count = 0;
	int bool = 1;
	int boolContinue = 0;
	
	printf("���������ã����Կ�ʼ��Ϸ��\n");

	while (1 == bool)
	{
		count++;
		int guessNum = -1; 
		printf("��%d�γ��Կ�ʼ�����²������Ϊ: ",count);
		scanf("%d", &guessNum);

		if (guessNum < guess)
		{
			printf("��С��\n");
		}

		else if (guessNum > guess) 
		{
			printf("�´���\n");
		}
		else 
		{
			printf("��ϲ���ڵ�%d�β����ˣ�\n", count);
			if (count <= 5) 
			{
				printf("�������һ�Ƚ���");
			}
			else if((5<count) &&(count <= 10))
			{
				printf("������˶��Ƚ�! ");
			}
			else 
			{
				printf("����������Ƚ�! ");
			}
			bool = 0;
		}
	}
	printf("�������Ϸ��(1/0): ");
	scanf("%d", &boolContinue);
	if (1 == boolContinue)
	{
		goto restart;
	}
	
	
	printf("��Ϸ������лл���룡");
	return 0;
	
}
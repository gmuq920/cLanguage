#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"game.h"

menu() 
{
	printf("***********************\n");
	printf("*****    1.Play   *****\n");
	printf("*****    0.Exit  ******\n");
	printf("***********************\n");
}

void game()
{
	char mine[ROWS][COLS];  //����׵���Ϣ
	char show[ROWS][COLS];   //�Ų�����׵���Ϣ

	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//��ӡ����
	DisplayBoard(show,ROW, COL);
	
	//������
	SetMine(mine, ROW, COL);

	//�鿴�������(�����ã�
	//DisplayBoard(mine, ROW, COL);

	//����
	FineMine(mine, show, ROW, COL);
}

void test() 
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		
		menu();
		printf("��ѡ��: ");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;

		case 0:
			printf("��Ϸ����\n");
			break;

		default:
			printf("ѡ�����������ѡ��\n");
			break;

		}
	} 
	while (input);
}

int main() 
{
	test();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
#include<stdlib.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char init)
{
	for (int i = 0; i < ROWS;i++)
	{
		for (int j = 0; j < COLS; j++) 
		{
			board[i][j] = init;
			
		}
	}
}

void DisplayBoard(char board[ROWS][COLS],int row, int col) 
{
	//��ӡ����
	printf("------ɨ����Ϸ------\n\n");
	for (int k = 0; k <= row;k++) {
		printf("%d ", k);
	}  
	//����
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		//��ӡ����
		printf("%d ", i);

		//��ӡʣ��9*9���
		for (int j = 1;j <= col;j++) 
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

//�������������ʮ��ֵ������
void SetMine(char board[ROWS][COLS], int row, int col)
{

	int x = 0;   //xȡֵ��Χ1-9
	int y = 0;   //yȡֵ��Χ1-9
	int count = EASY_COUNT;
	while (count) 
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		
		if (board[x][y] != '1') //�ж�֮ǰ��û����
		{
			board[x][y] = '1';//����һ����
			count--;
		}
		else
			continue;
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int totalMine = 0;
	for (int i = x - 1; i <= (x + 1);i++) 
	{
		for (int j = y - 1;j <= (y + 1);j++) 
		{
			totalMine = totalMine + mine[i][j] - '0';
		}
	}
	return totalMine;
}


void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int time = 0;
	

	while (win < ROW*COL-EASY_COUNT) 
	{
		
		printf("���������꣺");
		scanf("%d""%d", &y, &x);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if ('1' == mine[x][y])
			{
				printf("���ź���������ˣ���Ϸ����");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int mineNum = GetMineCount(mine, x, y);
				show[x][y] = mineNum +'0';
				system("cls");
				DisplayBoard(show, ROW, COL);
				win++;

			}
		}
		else
			printf("����Խ�����������롣");
	}
	//�ж��ǳɹ�����ʧ��
	if (win == ROW * COL - EASY_COUNT)
	{
		system("cls");
		printf("��ϲ�㣬��Ϸ�ɹ�!\n");
		DisplayBoard(mine, ROW, COL);
	}

}
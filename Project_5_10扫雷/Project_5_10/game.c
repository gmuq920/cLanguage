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
	//打印列数
	printf("------扫雷游戏------\n\n");
	for (int k = 0; k <= row;k++) {
		printf("%d ", k);
	}  
	//换行
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		//打印行数
		printf("%d ", i);

		//打印剩余9*9表格
		for (int j = 1;j <= col;j++) 
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

//在棋盘上随机找十个值布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{

	int x = 0;   //x取值范围1-9
	int y = 0;   //y取值范围1-9
	int count = EASY_COUNT;
	while (count) 
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		
		if (board[x][y] != '1') //判断之前有没有雷
		{
			board[x][y] = '1';//埋了一个雷
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
		
		printf("请输入坐标：");
		scanf("%d""%d", &y, &x);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if ('1' == mine[x][y])
			{
				printf("很遗憾，你踩雷了，游戏结束");
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
			printf("坐标越界请重新输入。");
	}
	//判断是成功还是失败
	if (win == ROW * COL - EASY_COUNT)
	{
		system("cls");
		printf("恭喜你，游戏成功!\n");
		DisplayBoard(mine, ROW, COL);
	}

}
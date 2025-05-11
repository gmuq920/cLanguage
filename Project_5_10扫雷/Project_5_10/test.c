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
	char mine[ROWS][COLS];  //存放雷的信息
	char show[ROWS][COLS];   //排查出的雷的信息

	//初始化数组
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//打印数组
	DisplayBoard(show,ROW, COL);
	
	//布置雷
	SetMine(mine, ROW, COL);

	//查看布置情况(试验用）
	//DisplayBoard(mine, ROW, COL);

	//排雷
	FineMine(mine, show, ROW, COL);
}

void test() 
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		
		menu();
		printf("请选择: ");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;

		case 0:
			printf("游戏结束\n");
			break;

		default:
			printf("选择错误，请重新选择。\n");
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
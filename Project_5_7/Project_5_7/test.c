#define _CRT_SECURE_NO_WARNINGS



////try goto 制作重启代码（密码输入正确中止重启）
//
//#include <string.h>
//#include<stdlib.h>
//#include<stdio.h>
//
//int main() 
//{
//	char kb[20] = { 0 };
//	system("shutdown -s -t 60");
//	printf("电脑将会在60s后关机，请输入正确电脑密码停止。\n");
//	printf("您的密码为：");
//again:
//
//	scanf("%s", kb);
//	if (strcmp(kb, "750219") == 0)
//	{
//		system("shutdown -a");
//		printf("密码正确，关机操作已被取消。");
//	}
//
//	else
//	{
//		printf("密码错误，请再次输入：");
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
	printf("欢迎进入猜数字游戏，数字范围为0-100。\n");
restart:

	
	int guess = rand() % 100 + 1;
	int count = 0;
	int bool = 1;
	int boolContinue = 0;
	
	printf("数字已重置，可以开始游戏。\n");

	while (1 == bool)
	{
		count++;
		int guessNum = -1; 
		printf("第%d次尝试开始，您猜测的数字为: ",count);
		scanf("%d", &guessNum);

		if (guessNum < guess)
		{
			printf("猜小了\n");
		}

		else if (guessNum > guess) 
		{
			printf("猜大了\n");
		}
		else 
		{
			printf("恭喜您在第%d次猜中了！\n", count);
			if (count <= 5) 
			{
				printf("您获得了一等奖！");
			}
			else if((5<count) &&(count <= 10))
			{
				printf("您获得了二等奖! ");
			}
			else 
			{
				printf("您获得了三等奖! ");
			}
			bool = 0;
		}
	}
	printf("想继续游戏吗(1/0): ");
	scanf("%d", &boolContinue);
	if (1 == boolContinue)
	{
		goto restart;
	}
	
	
	printf("游戏结束，谢谢参与！");
	return 0;
	
}
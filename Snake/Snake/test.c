#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include"snake.h"

void test()
{
	int ch = 0;
	do {
		//system("cls");

		Snake snake = { 0 };

		GameStart(&snake);

		GameRun(&snake);

		GameEnd(&snake);

		SetPos(20, 15);
		
		printf("Would you like to try again(Y/N):");

		ch = getchar();
		getchar();

	}while (ch == 'Y' || ch == 'y');


	SetPos(0, 27);
}

int main()
{
	//set local
	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "");
	test();

	return 0;
	
}
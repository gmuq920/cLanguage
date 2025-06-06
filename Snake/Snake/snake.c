#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"

void SetPos(short x, short y)
{
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelcomeToGame()
{
	SetPos(40, 14);
	printf("Welcome to SNAKE!!");
	
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(20, 14);
	printf("Use ¡ü ¡ý ¡û ¡ú  to control the snake. Press F3 to Speed UP, F4 to SLOW DOWN. \n");
	SetPos(20, 15);
	printf("Score higher by moving faster!");
	SetPos(42, 20);
	system("pause");
	system("cls");
}

void CreateMap() 
{
	SetPos(0, 0);
	for (int i = 0;i < 29;i++) 
	{
		wprintf(WALL);
	}
	SetPos(0, 26);
	for (int i = 0;i < 29;i++)
	{
		wprintf(WALL);
	}
	
	for (int i = 1;i <= 25;i++)
	{
		SetPos(0, i);
		wprintf(WALL);
	}
	
	for (int i = 1;i <= 25;i++)
	{
		SetPos(56, i);
		wprintf(WALL);
	}
	//getchar();
	//system("pause");
}

void InitSnake(pSnake ps) 
{
	pSnakeNode cur = NULL;
	for (int i = 0;i < 5;i++) 
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL) 
		{
			perror("Init: Malloc");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + i*2;
		cur->y = POS_Y;

		if (ps->_psnake == NULL) 
		{
			ps->_psnake = cur;
		}
		else
		{
			cur->next = ps->_psnake;
			ps->_psnake = cur;
		}
	}
	while (cur) 
	{
		SetPos(cur->x, cur->y);
		wprintf(BODY);
		cur = cur->next;
	}
	//SET SNAKE
	ps->_dir = RIGHT; 
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;
	ps->_status = OK;
}

void CreateFood(pSnake ps) 
{
	int x = 0;
	int y = 0;
again:
	do {
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0 );
	
	pSnakeNode cur = ps->_psnake;
	
	while (cur)
	{
		if (x == cur->x && y == cur->y) 
		{
			goto again;
		}
		cur = cur->next;
	}
	pSnakeNode pfood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pfood == NULL) 
	{
		perror("pfood: malloc");
		return;
	}
	pfood->x = x;
	pfood->y = y;
	pfood->next = NULL;

	SetPos(x, y);
	wprintf(FOOD);
	ps->_pfood = pfood;
}


void GameStart(pSnake ps)
{
	system("mode con cols=100 lines=30");
	system("title Snake");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput, &CursorInfo);

	WelcomeToGame();

	CreateMap();

	InitSnake(ps);

	CreateFood(ps);
}

void PrintHelpInfo(pSnake ps) 
{
	SetPos(70, 10);
	printf("Use ¡ü ¡ý ¡û ¡ú  to control the snake. \n");
	SetPos(70, 11);
	printf("Press F3 to Speed UP, F4 to SLOW DOWN.\n");
	SetPos(70, 12);
	printf("Score higher by moving faster!\n");
	SetPos(70, 13);
	printf("Press ESC to quit.\n");
	/*SetPos(70, 16);
	printf("Current Score is %d.", ps->_score);*/
	//getchar();
}
void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
			break;
	}
}
int NextIsFood(pSnakeNode pn,pSnake ps) 
{
	return (pn->x == ps->_pfood->x && pn->y == ps->_pfood->y);
}

void EatFood(pSnakeNode pn, pSnake ps) 
{
	pn->next = ps->_psnake;
	ps->_psnake = pn;
	pSnakeNode cur = pn;
	pn = NULL;
	
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps) 
{
	pn->next = ps->_psnake;
	ps->_psnake = pn;
	pSnakeNode cur = pn;
	while (cur->next->next) 
	{
		SetPos(cur->x, cur->y);
		wprintf(BODY);
		cur = cur->next;
	}
	
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

void KillByWall(pSnake ps)
{
	if (ps->_psnake->x == 0 || ps->_psnake->x == 56 || ps->_psnake->y == 0 || ps->_psnake->y == 26) 
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps) 
{
	pSnakeNode cur = ps->_psnake->next;
	while (cur)
	{
		if (cur->x == ps->_psnake->x && cur->y == ps->_psnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps) 
{
	pSnakeNode pNextNode =(pSnakeNode) malloc(sizeof(SnakeNode));
	if (pNextNode == NULL) 
	{
		perror("SnakeMove: malloc");
		return;
	}

	switch (ps->_dir) 
	{
	case UP: 
		pNextNode->y = ps->_psnake->y - 1;
		pNextNode->x = ps->_psnake->x;
		pNextNode->next = ps->_psnake;
		break;
	
	case DOWN: 
		pNextNode->y = ps->_psnake->y + 1;
		pNextNode->x = ps->_psnake->x;
		pNextNode->next = ps->_psnake;
		break;

	case LEFT:
		pNextNode->y = ps->_psnake->y;
		pNextNode->x = ps->_psnake->x-2;
		pNextNode->next = ps->_psnake;
		break;

	case RIGHT:
		pNextNode->y = ps->_psnake->y;
		pNextNode->x = ps->_psnake->x+2;
		pNextNode->next = ps->_psnake;
		break;
	}

	if (NextIsFood(pNextNode,ps) )
	{
		EatFood(pNextNode, ps);
		pNextNode = NULL;
	}
	else 
	{
		NoFood(pNextNode, ps);
	}

	KillByWall(ps);

	KillBySelf(ps);

}
void GameRun(pSnake ps) 
{
	PrintHelpInfo(ps);

	do {
		SetPos(70, 16);
	    printf("Current Score is %d.", ps->_score);
		SetPos(70, 17);
		printf("Current FoodScore is %2d.", ps->_food_weight);
		
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}

		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}

		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}

		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}

		else if (KEY_PRESS(VK_SPACE)) 
		{
			Pause();
		}

		else if(KEY_PRESS(VK_ESCAPE))
		{
			ps->_status = END_NORMAL;
		}

		else if(KEY_PRESS(VK_F3))
		{
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}

		else if(KEY_PRESS(VK_F4))
		{
			if (ps->_sleep_time < 320)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		SnakeMove(ps);
		Sleep(ps->_sleep_time);
	} while (ps->_status == OK);
}

void GameEnd(pSnake ps)
{
	system("cls");
	SetPos(42, 10);
	printf("GAME OVER!!");
	SetPos(42, 11);
	if (ps->_status == KILL_BY_WALL) 
	{
		printf("The snake crashed into the wall!\n");
		SetPos(42, 12);
		printf("Final score is %d!", ps->_score);
	}

	else if (ps->_status == KILL_BY_SELF) 
	{
		printf("The snake crashed into its own body! \n");
		SetPos(42, 12);
		printf("Final score is %d!", ps->_score);
	}
	
	//Free nodes
	pSnakeNode cur = ps->_psnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}

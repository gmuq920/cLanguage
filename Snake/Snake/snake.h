#define _CRT_SECURE_NO_WARNINGS

#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define POS_X 24
#define POS_Y 5
#define WALL L"墙"
#define BODY L"蛇"
#define FOOD L"食"
#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)

enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL
};

//Build snake node;
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, *pSnakeNode;

//typefef struct SnakeNode* *pSnakeNode

typedef struct Snake
{
	pSnakeNode _psnake; //point to the snakehead
	pSnakeNode _pfood; //point to the food
	enum DIRECTION _dir;
	enum GAME_STATUS _status;
	int _food_weight;  //food point
	int _score;      //Score
	int _sleep_time;   //Snake speed

}Snake, * pSnake;

void GameStart(pSnake ps);

void WelcomeToGame();

void CreateMap();

void InitSnake(pSnake ps);

void CreateFood(pSnake ps);

void GameRun(pSnake ps);

void SnakeMove(pSnake ps);

int NextIsFood(pSnakeNode pNextNode,pSnake ps);

void EatFood(pSnakeNode pNextNode, pSnake ps);

void NoFood(pSnakeNode pNextNode, pSnake ps);

void KillByWall(pSnake ps);

void KillBySelf(pSnake ps);

void GameEnd(pSnake ps);

void SetPos(short x, short y);

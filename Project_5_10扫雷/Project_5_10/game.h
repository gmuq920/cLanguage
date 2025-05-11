#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

#include<time.h>

void InitBoard(char board[ROWS][COLS],int rows ,int cols, char init);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
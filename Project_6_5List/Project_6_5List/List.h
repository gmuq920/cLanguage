#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode 
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* LTInit();
void LTDestroy(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);

void LTPushFront(LTNode* phead, LTDataType x);

void LTPrint(LTNode* phead);

void LTPopBack(LTNode* phead);

void LTPopFront(LTNode* phead);

void LTInsert(LTNode* pos, LTDataType x);

void LTErase(LTNode* pos);

LTNode* LTFind(LTNode* phead, LTDataType x);
#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

LTNode* LTBuyNode(LTDataType x) 
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL) {
		perror("Malloc fail");
		return 1;
	}
	node->data = x;
	node->next = node;
	node->prev = node;
	return node;
}
LTNode* LTInit() 
{
	return LTBuyNode(-1);
}


void LTPushBack(LTNode* phead, LTDataType x) 
{
	assert(phead);
	LTNode* newNode = LTBuyNode(x);
	newNode->next = phead;
	newNode->prev = phead->prev;
	phead->prev->next = newNode;
	phead->prev = newNode;
	
}

void LTPushFront(LTNode* phead, LTDataType x) 
{
	assert(phead);
	LTNode* newNode = LTBuyNode(x);
	newNode->next = phead->next;
	newNode->prev = phead;
	phead->next->prev = newNode;
	phead->next = newNode;
}

void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
    assert(phead);
	while (pcur != phead) 
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
void LTPopBack(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* newPrev = phead->prev->prev;
	free(phead->prev);
	newPrev->next = phead;
	phead->prev = newPrev;
}

void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x) 
{
	assert(phead && phead->next != phead);
	LTNode* pcur = phead->next;
	while (pcur != phead) 
	{
		if (pcur->data == x) 
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x) 
{
	assert(pos);
	LTNode* newNode = LTBuyNode(x);
	newNode->next = pos->next;
	newNode->prev = pos;
	pos->next->prev = newNode;
	pos->next = newNode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

void LTDestroy(LTNode* phead) 
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead) 
	{
		LTNode* pcurNext = pcur->next;
		free(pcur);
		pcur = pcurNext;
	}
	free(phead);
	phead = NULL;
}
#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"


void SLTPrint(SLTNode* phead) 
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) 
	{
		perror("Malloc");
		return 1;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
    //Malloc spaces for the neenode	
	SLTNode* newnode = SLTBuyNode(x);
	//*pphead is the pointer for the first node, check if it is NULL.
	if (*pphead == NULL)
	{
		//the first node is NULL, then change the first node to the newnode.
		*pphead = newnode;
	}

	//If the first node is not NULL , find the tile of the SList(pushback), then insert the newcode.
	else
	{
        SLTNode* ptile = *pphead;
		while (ptile->next != NULL)
		{
			ptile = ptile->next;
		}

		ptile->next = newnode;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead); 
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode; 
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	//Check nodes number;
	if ((*pphead)->next == NULL) 
	{
		//Only one node
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//more than one node
		SLTNode* ptile = *pphead;
		SLTNode* pprev = *pphead;
		while (ptile->next)
		{
			pprev = ptile;
			ptile = ptile->next;
		}
		free(ptile);
		ptile = NULL;
		pprev->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead) 
{
	assert(pphead && *pphead);
	//That's important to use () for (*pphead).
	SLTNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) 
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) 
{
	assert(pphead && *pphead && pos);
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else 
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x) 
{
	assert(pos);
	SLTNode* next = pos->next;
	pos->next = SLTBuyNode(x);
	pos->next->next = next;
}

void SLTErase(SLTNode** pphead, SLTNode* pos) 
{
	assert(*pphead && pphead && pos);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else 
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		
		prev->next = pos->next;
		free(pos);
		pos == NULL;
	}
}

void SLTEraseAfter(SLTNode* pos) 
{
	assert(pos && pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SLTDestroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = *pphead;
	SLTNode* des = *pphead;
	while (next)
	{
		next = next->next;
		free(des);
		des = next;
	}
	*pphead = NULL;
}
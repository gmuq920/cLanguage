#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void QueueInit(Queue* pq) 
{
	assert(pq);
	pq->phead = NULL;
	pq->ptile = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x) 
{
	assert(pq);

	QNode* tmp = (Queue*)malloc(sizeof(QNode));
	if (tmp == NULL) {
		perror("malloc");
		return;
	}
	tmp->val = x;
	if (pq->phead ==  NULL)
	{
		pq->phead = pq->ptile = tmp;
	}
	pq->ptile->next = tmp;
	tmp->next = NULL;
	pq->ptile = tmp;
	pq->size++;
}


void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size > 0);
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptile = NULL;
	}
	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	pq->size--;
}

QDataType QueueFront(Queue* pq) 
{
	return pq->phead->val;
}

QDataType QueueBack(Queue* pq) 
{
	assert(pq);
	return pq->ptile->val;
}

int QueueSize(Queue* pq) 
{
	assert(pq);
	return pq->size;
}


bool QueenEmpty(Queue* pq) 
{
	assert(pq);
	return pq->size == 0;
}

void QueenDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur) 
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptile = NULL;
	pq->size = 0;

}
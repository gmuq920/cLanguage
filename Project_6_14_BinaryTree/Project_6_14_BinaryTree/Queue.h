#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct BTNode* QDataType;

typedef struct QueueNode 
{
	struct QueueNode* next;
	QDataType val;
}QNode;

typedef struct Queue 
{
	QNode* phead;
	QNode* ptile;
	int size;
}Queue;

void QueueInit(Queue* pq);

void QueuePush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);

bool QueueEmpty(Queue* pq);

void QueueDestroy(Queue* pq);

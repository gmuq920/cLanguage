#define _CRT_SECURE_NO_WARNINGS

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


typedef int SLDataType;

typedef struct SeqList 
{
	SLDataType* arr;
	int size;    //available data numbers
	int capacity;  
}SL;

//Sequence list initialize
void SLInit(SL* ps); 

//Sequence list destroy
void SLDestroy(SL* ps);

void SLPushBack(SL* ps, SLDataType x);

void SLPushFront(SL* ps, SLDataType x);

void SLPopBack(SL* ps);

void SLPopFront(SL* ps);

void SLInsert(SL* ps, int pos, SLDataType x);

void SLErase(SL* ps, int pos);

int SLFind(SL* ps, SLDataType x);


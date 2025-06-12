#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Heap 
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);

void HPDestroy(HP* php);
void HPPush(HP* php, HPDataType x);

void HPPop(HP* php);

HPDataType HPTop(HP* php);

bool HPEmpty(HP* php);

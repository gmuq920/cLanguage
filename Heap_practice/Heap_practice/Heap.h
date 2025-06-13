#define _CRT_SECURE_NO_WARNINGSdef
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//Large heap(Largest number at top)
typedef int HPDataType;
typedef struct Heap{
	HPDataType* a;
	int capacity;
	int size;
}HP;

void HPInit(HP* php);

void HPPush(HP* php, HPDataType x);

void HPPop(HP* php);

void HPDestroy(HP* php);

HPDataType HPTop(HP* php);

bool HPEmpty(HP* php);

int HPSize(HP* php);

void AdjustUp(HPDataType* a, int child);

void AdjustDown(HPDataType* a, int size, int child);

void HeapSort(int* a, int size);

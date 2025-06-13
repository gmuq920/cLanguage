#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2) {
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	
}

void AdjustUp(HPDataType* a, int child) 
{
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int size, int parent) 
{
	int child = parent * 2 + 1;
	while (child < size) 
	{
		if (child + 1 < size && a[child] < a[child + 1])
		{
			child += 1;
		}

		if (a[child] > a[parent]) 
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else 
		{
			break;
		}
		
	}
}

void HPInit(HP* php) 
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	php->a = NULL;
	free(php->a);
	php->size = php->capacity = 0;
}

void HPPush(HP* php, HPDataType x) 
{
	assert(php);
	//Realloc new capacity for the heap;
	if (php->size == php->capacity) 
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a,sizeof(HPDataType) * newCapacity);
		if (tmp == NULL) {
			perror("Malloc failed!");
			return;
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size-1);
}

//Pop the first number;
void HPPop(HP* php)
{
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);

}

HPDataType HPTop(HP* php) {
	return php->a[0];
}

bool HPEmpty(HP* php) {
	return php->size == 0;
}

int HPSize(HP* php) {
	return php->size;
}

void HeapSort(int* a, int size)
{
	//Build up heap from down to up;
	int end = (size-2)/2;
	while (end >= 0) {
		AdjustDown(a, size , end);
		end--;
	}
	for (int i = 0; i < size;i++) 
	{
		Swap(&a[0], &a[size -1- i]);
		AdjustDown(a, size - 1 - i, 0);
	}


}


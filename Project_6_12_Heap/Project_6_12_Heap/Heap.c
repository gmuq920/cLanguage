#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"


void Swap(HPDataType* p1, HPDataType* p2) 
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HPDestroy(HP* php) 
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}


void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0) 
	{
		if (a[child] < a[parent])
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
	int child = 2 * parent + 1;
	while(child < size) 
	{
		if (child+1<size && a[child] > a[child + 1])
		{
			child += 1;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}


void HPPush(HP* php, HPDataType x)
{
	assert(php);
	// realloc;
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * (sizeof(HPDataType)));
		if (tmp == NULL) {
			perror("Realloc");
			return;
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}

	//insert x
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
	
}

HPDataType HPTop(HP* php) 
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

void HPPop(HP* php) 
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;

	AdjustDown(php->a,php->size,0);
}

bool HPEmpty(HP* php) 
{
	return php->size == 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void TestHeap01()
{
	HP hp;
	HPInit(&hp);
	int a[10] = { 1,2,5,4,7,8,9,0,3,6 };
	for (int i = 0;i < 10;i++) 
	{
		HPPush(&hp, a[i]);
	}
	while(!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	
	
}

int main() {
	TestHeap01();
	return 0;
}
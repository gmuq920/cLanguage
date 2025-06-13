#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
#include<time.h>
//#include"Heap.c"


//int main() 
//{
//	/*HP php;
//	HPInit(&php);
//	HPPush(&php, 1);
//	HPPush(&php, 12);
//	HPPush(&php, 3);
//	HPPush(&php, 4);
//	HPPush(&php, 15);
//	HPPush(&php, 7);
//
//	for (int i = 0;i < 5;i++) {
//		printf("%d ", php.a[i]);
//	}
//
//	printf("\n");
//	HPPop(&php);
//	for (int i = 0;i < 4;i++) {
//		printf("%d ", php.a[i]);
//	}
//	printf("\n");
//	HPPop(&php);
//	for (int i = 0;i <3;i++) {
//		printf("%d ", php.a[i]);
//	}*/
//
//	int list[15]  = { 1,3,5,7,9,2,4,6,8,10};
//	int size = 10;
//	HeapSort(list, size);
//	for (int i = 0;i < 10;i++) {
//		printf("%d ", list[i]);
//	}
//
//}


void CreateNDate()
{
	// дьЪ§Он
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

//void PrintTopK(int k);

int main() {
	//CreateNDate();
	FILE* file = fopen("data.txt", "r");
	int k = 0;;
	printf("Input the number of K ->");
	scanf("%d", &k);
	int* p = (int*)malloc(sizeof(int) * k);
	for (int i = 0;i < k;i++) {
		fscanf(file, "%d", (p + i));
	}

	int end = (k - 2) / 2;
	while (end >= 0) {
		AdjustDown(p, k, end);
		end--;
	}
	int tmp = 0;
	while (fscanf(file, "%d", &tmp) != EOF)
	{
		if (tmp < *p) 
		{
			*p = tmp;
			AdjustDown(p, 10, 0);
		}
	}

	HeapSort(p, k);
	for (int i = 0;i < k;i++) {
		printf("%d ", *(p + i));
	}
}
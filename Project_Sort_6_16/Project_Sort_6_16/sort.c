#define _CRT_SECURE_NO_WARNINGS
#include"sort.h"

void Swap(int* p1, int* p2) 
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(int* list, int parent,int size) 
{
	int child = parent * 2 + 1;
	
	while (child < size) 
	{
		if (list[child + 1] > list[child])
		{
			child += 1;
		}
		if (list[child] > list[parent]) 
		{
			Swap(&list[child], &list[parent]);
			parent = child;
			child = parent * 2 + 1;
			
		}
	}
}

//Print Function
void PrintArray(int* array, int size)
{
	for (int i = 0;i < size;i++)
	{
		printf("%d ", array[i]);
	}
}


void Heap_Sort(int* list, int size)
{
	int end = (size - 2) / 2;
	while (end >= 0) 
	{
		AdjustDown(list,end,size-1);
		end--;
	}
	int tmp = size-1;
	while (tmp >= 0) 
	{
		Swap(&list[0], &list[tmp]);
		tmp--;
		AdjustDown(list, 0, tmp);
	}
}

void Bubble_Sort(int* list, int size) 
{
	int tmp = size - 1;
	while (tmp > 0) {
		for (int i = 0;i < tmp;i++) {
			if (list[i] > list[i + 1]) 
			{
				Swap(&list[i], &list[i + 1]);
			}
		}
		tmp--;
	}
}


//void Shell_Sort(int* list, int size)
//{
//	int gap = size / 2;
//	while (gap > 0)
//	{
//		for (int i = gap; i < size; i++)
//		{
//			int tmp = list[i];
//			int j = i;
//			while (j >= gap && list[j - gap] > tmp)
//			{
//				list[j] = list[j - gap];
//				j -= gap;
//			}
//			list[j] = tmp;
//		}
//		gap /= 2;
//	}
//}


void Shell_Sort(int* list, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap;i < size;i++) {
			int cur = i;
			int tmp = list[cur];
			while (cur >= gap) {
				if (tmp < list[cur - gap]) {
					list[cur] = list[cur - gap];
					cur -= gap;
				}
				else
					break;
			}
			list[cur] = tmp;
		}
	}
}

void Select_Sort(int* list, int size)
{
	for (int i = 0;i < size;i++)
	{
		int tmp = list[i];
		int smallest = i;
		for (int j = i;j < size;j++) 
		{
			if (list[j] < list[smallest]) {
				smallest = j;
			}
		}
		list[i] = list[smallest];
		list[smallest] = tmp;
	}
}

void Insert_Sort(int* list, int size)
{
	//i is the number needs to be Sort;
	for (int i = 0;i < size - 1;i++)
	{
		int end = i;
		int tmp = list[end + 1];
		while (end >= 0)
		{
			if (tmp < list[end]) {

				list[end + 1] = list[end];
				end--;
			}
			else {
				break;
			}
		}
		list[end + 1] = tmp;
	}
}


int Mid(int* list, int size)
{
	int mid = size / 2-1;
	if (list[0] > list[size - 1])
	{
		if (list[0] < list[mid])
		{
			return 0;
		}
		else if (list[size - 1] > list[mid])
		{
			return size - 1;
		}
		else
			return mid;
	}
	else {
		if (list[0] < list[mid]) {
			return 0;
		}
		else if(list[mid]<list[size-1])
		{
			return size - 1;
		}
		else {
			return mid;
		}
			
	}


}

void Quick_Sort(int* list, int size) 
{
	if (size <= 1) {
		return;
	}
	if (size <= 10) {
		Insert_Sort(list, size);
		return;
	}

	
	int mid = Mid(list, size);
	Swap(&list[0], &list[mid]);
	
	int tmp = list[0];
	int i = 1;
	int j = size - 1;
	while (i < j) 
	{
		while (list[j] > tmp) {
			j--;
			if (i == j) {
				break;
			}
		}
		while (list[i] < tmp) {
			i++;
			if (i == j) {
				break;
			}
		}
		if (i < j) {
			Swap(&list[i], &list[j]);
		}

	}
	Swap(&list[0], &list[i]);
	Quick_Sort(list, i);
	Quick_Sort(list+i+1, size - i-1);

}

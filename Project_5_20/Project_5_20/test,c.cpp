#define _CRT_SECURE_NO_WARNINGS

//// use qsort to arrange int array
//#include<stdio.h>
//#include<stdlib.h>
//int cmp_arr(const void* p1, const void* p2) 
//{
//	/*if (*(int*)p1 > *(int*)p2)
//	{
//		return 1;
//	}
//	else 
//		return -1;*/
//	return (*(int*)p1 - *(int*)p2);
//}
//void Print_Arr(int array[],int sz) 
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", array[i]);
//	}
//}
//void test() 
//{
//	int array[] = { 1,6,5,8,9,0,2,7,7,3,7,4 };
//	int sz = sizeof(array) / sizeof(array[0]);
//	qsort(array, sz, sizeof(array[0]), cmp_arr);
//	Print_Arr(array,sz);
//}
//int main()
//{
//	test();
//	return 0;
//}
//


//use qsort to arrange struct
#include<stdio.h>
#include<stdlib.h>

struct stu 
{
	char name[20];
	int age;
};


int sort_by_age(const void* p1, const void*p2)
{
	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
}

int sort_by_first_letter(const void* p1, const void* p2) 
{
	return ((struct stu*)p1)->name[0] - ((struct stu*)p2)->name[0];
}

int main() 
{
	stu students[] = { {"Andy",28},{"Michael",23},{"Justin",20} };
	int sz = sizeof(students) / sizeof(students[0]);
	int input = 0;
	printf("How to sort the students?\n");
	printf("1.Sort by age.\n");
	printf("2.Sort by name's first letter.\n");
	printf("Input your choice:");
	scanf("%d", &input);
	switch (input) 
	{
	case 1:
		qsort(students, sz, sizeof(students[0]), sort_by_age);
		break;
	case 2:
		qsort(students, sz, sizeof(students[0]), sort_by_first_letter);
		break;
	default:
		printf("Invalid input.");
		break;

	}		
	return 0;
}
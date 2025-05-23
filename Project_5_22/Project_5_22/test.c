#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>
////practice qsort
//
//struct stu
//{
//	char name[20];
//	int age;
//	char major;//c---Computer, m---Mathsmatic,e---Economic
//};
//
//int cmp_by_age(const void* p1,const void*p2 ) 
//{
//	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
//}
//
//int cmp_by_name(const void* p1, const void* p2)
//{
//	return ((struct stu*)p1)->name[0] - ((struct stu*)p2)->name[0];
//}
//
//
//int main() 
//{
//	struct stu students[3] = { { "Andy", 20,'c'},{ "Michael",23,'m' },{ "Jason",18,'e' } };
//	int sz = sizeof(students) / sizeof(students[0]);
//	qsort(students, sz, sizeof(students[0]), cmp_by_age);
//	//qsort(students, sz, sizeof(students[0]), cmp_by_name);
//	return 0;
//}

////strlen
//#include<stdio.h>
//int main() 
//{
//	char str[] = "abcdef";
//	int i = 0;
//	int count = 0;
//	char* p = str;
//	while (*p != '\0')
//	{
//		p ++ ;
//		count++;
//	}
//	printf("%d", count);
//
//	return 0;
//}



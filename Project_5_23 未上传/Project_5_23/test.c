#define _CRT_SECURE_NO_WARNINGS

//
//#include<stdio.h>
//
//void* my_memcpy(void* dest, const void* source, size_t sz)
//{
//	void* ret = dest;
//	for (int i = 0;i < sz; i++) 
//	{
//		*(char*)dest = *(char*)source;
//		dest = (char*)dest + 1;
//		source = (char*)source + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char string1[] = "abcdef";
//	char string2[20] = { 0 };
//	char* ret = my_memcpy(string2, string1+2, 20);
//	printf("%s\n", ret);
//	return 0;
//}
//
//#include<stdio.h>
////memmove
//void* memmove(void* dest, const void* src, size_t sz) 
//{
//	void* ret = dest;
//	if (dest < src) {
//		while (sz--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (sz--) {
//
//			*((char*)dest+sz) = *((char*)src+sz);
//			
//		}	
//	}
//	return ret;
//}
//int main()
//{
//	char string[] = "abcdefghijk";
//	memmove(string +2, string, 20);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int a = 1;
	int* p = &a;
	int num = *(char*)p;
	printf("%d", num);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

int main() 
{
	ST* pst ;
	STInit(&pst);
	STPush(&pst, 1);
	printf("%d\n", pst->a[pst->top - 1]);
	STPush(&pst, 2);
	
	return 0;
}
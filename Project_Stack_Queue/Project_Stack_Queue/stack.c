#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//top point to top number.next
	pst->top = 0;
	
	pst->capacity = 0;

}
void STDestry(ST* pst) 
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
void STPush(ST* pst, STDataType x) 
{
	assert(pst);
	if (pst->capacity = pst->top)
	{
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst, newCapacity*(sizeof(STDataType)));
		if (tmp == NULL) {
			perror("realloc");
			return;
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
STDataType STTop(ST* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}
bool STEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;

}
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
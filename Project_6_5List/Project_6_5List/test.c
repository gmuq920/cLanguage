#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

void ListTest01() 
{
	LTNode* plist = LTInit();
	
	/*LTPushBack(plist, 1);
	LTPrint(plist);*/
	LTPushFront(plist, 1);
	LTPrint(plist);
	LTPushFront(plist, 2);
	LTPrint(plist);
	LTPushFront(plist, 3);
	LTPrint(plist);
	/*LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);*/
	/*LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);*/
	/*LTNode* find = LTFind(plist, 30);
	if (find == NULL)
	{
		printf("Not found! ");
	}
	else
		printf("Find it£¡");*/

	LTInsert(LTFind(plist,3), 4);
	LTPrint(plist);
	LTErase(LTFind(plist, 1));
	LTPrint(plist);
	LTDestroy(plist);
	plist = NULL;

}

int main()
{
	ListTest01();
	return 0;
}
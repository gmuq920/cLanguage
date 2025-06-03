#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
void SListTest01()
{
	//create some new nodes
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	node1->data = 1;

	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	node2->data = 2;
	
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	node3->data = 3;

	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	node4->data = 4;

	//connect the nodes;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//print the slist;
	SLTNode* plist = node1;
	SLTPrint(plist);
}

void SListTest02() 
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);
	SLTInsert(&plist, SLTFind(plist,3), 5);
	SLTInsertAfter(SLTFind(plist, 3), 20);
	SLTPrint(plist);
	SLTErase(&plist, SLTFind(plist, 1));
	SLTPrint(plist);
	SLTEraseAfter(SLTFind(plist, 5));

	SLTPrint(plist);
	SLTDestroy(&plist);
	SLTPrint(plist);


}

void SListTest03() 
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushBack(&plist, 4);
	
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopBack(&plist);
	//SLTPopFront(&plist);
	SLTPrint(plist);
	
}

void SListTest04() 
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTNode* findNode = SLTFind(plist, 3);
	if (findNode == NULL)
	{
		printf("No result. \n");
	}
	else
		printf("Got it! \n");


}
int main()
{
	//SListTest01();
	SListTest02();
	//SListTest03();
	//SListTest04();
	return 0;
}
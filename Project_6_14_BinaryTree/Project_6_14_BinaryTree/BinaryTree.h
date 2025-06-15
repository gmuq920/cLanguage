#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int BTDataType;
typedef struct BTNode
{
	BTDataType val;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x);

void PrevOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

int TreeSize(BTNode* root);

int TreeLeafSize(BTNode* root);

int TreeHeight(BTNode* root);

int TreeLevelKSize(BTNode* root,int k);

BTNode* TreeFind(BTNode* root, BTDataType x);

void TreeDestroy(BTNode* root);

void TreeLevelOrder(BTNode* root);

//void TreeComplete(BTNode* root);

bool TreeComplete(BTNode* root);


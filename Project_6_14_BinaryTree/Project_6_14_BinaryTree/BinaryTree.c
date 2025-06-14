#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
//#include<stdbool.h>


BTNode* BuyNode(BTDataType x) 
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (tmp == NULL) {
		perror("Malloc failed");
		return;
	}
	tmp->val = x;
	tmp->left = NULL;
	tmp->right = NULL;
}


void PrevOrder(BTNode* root) 
{
	if (root == NULL) {
		printf("N ");
		return;
	}

	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);

}

void InOrder(BTNode* root) 
{
	if (root == NULL) {
		printf("N ");
		return;
	}
	PrevOrder(root->left);
	printf("%d ", root->val);
	PrevOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL) {
		printf("N ");
		return;
	}
	PrevOrder(root->left);
	PrevOrder(root->right);
	printf("%d ", root->val);

}
int TreeSize(BTNode* root) 
{
	if (root == NULL) {
		return 0;
	}

	return TreeSize(root->left) + TreeSize(root->left) + 1;
}

int TreeLeafSize(BTNode* root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	if (root->left == NULL  &&  root->right == NULL) {
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	
}


int TreeHeight(BTNode* root)
{
	if (root == NULL) {
		return 0;
	}
	int left = TreeHeight(root->left)+1;
	int right = TreeHeight(root->right)+1;
	return left > right ? left : right;
}

int TreeLevelKSize(BTNode* root,int k) 
{
	if (root == NULL)
		return 0;
	if(k == 1)
		return 1;
	
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	
	if (root->val == x) 
		return root;
	

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}
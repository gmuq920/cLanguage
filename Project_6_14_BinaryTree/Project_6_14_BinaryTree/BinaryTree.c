#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
#include"Queue.h"

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

bool isSameTree(BTNode* tree1, BTNode* tree2) 
{
	if (tree1 == NULL && tree2 == NULL) {
		return true;
	}
	if (tree1 == NULL || tree2 == NULL) {
		return false;
	}
	if (tree1->val != tree2->val) {
		return false;
	}
	return isSameTree(tree1->left, tree2->left) && isSameTree(tree1->right,tree2->right);
}

void TreeDestroy(BTNode* root) 
{
	if (root == NULL) {
		return;
	}

	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}

void TreeLevelOrder(BTNode* root) 
{
	Queue q;
	QueueInit(&q);
	if (root) {
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", front->val);
		

		if (front->left) {
			QueuePush(&q, front->left);
		}

		if (front->right) {
			QueuePush(&q, front->right);
		}
	}

	QueueDestroy(&q);

}

//void TreeComplete(BTNode* root) {
//	Queue q;
//	QueueInit(&q);
//	char tmp[100];
//	int size = 0;
//	if (root) {
//		QueuePush(&q, root);
//	}
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front == NULL) {
//			tmp[size] = '#';
//			size++;
//		}
//		else
//		{
//			tmp[size] = '*';
//			size++;
//			QueuePush(&q, front->left);
//			QueuePush(&q, front->right);
//		}
//
//	}
//	for (int i = 0;i < size;i++) {
//		printf("%c ", tmp[i]);
//	}
//	printf("\n");
//	int cur = 0;
//	while (tmp[cur] != '#') {
//		cur++;
//	}
//	for (int i = cur;i < size;i++) {
//		if (tmp[i] != '#') {
//			printf("NO");
//			return;
//		}
//	}
//
//	printf("yes");
// 
//}

bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root) {
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front) {
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;

}



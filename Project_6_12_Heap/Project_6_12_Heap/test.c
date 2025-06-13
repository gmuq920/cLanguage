#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
#include<time.h>


//void TestHeap01()
//{
//	HP hp;
//	HPInit(&hp);
//	int a[10] = { 1,2,5,4,7,8,9,0,3,6 };
//	for (int i = 0;i < 10;i++) 
//	{
//		HPPush(&hp, a[i]);
//	}
//	while(!HPEmpty(&hp))
//	{
//		printf("%d ", HPTop(&hp));
//		HPPop(&hp);
//	}
//	
//	
//}

void CreateData() 
{
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file,"w");
	if (fin == NULL) {
		perror("File");
		return;
	}
	for (int i = 0;i < n;i++) 
	{
		int x = rand() + i;
		fprintf(fin, "%d\n", x);

	}
	fclose(fin);

}

void TestHeap02() 
{
	int k = 0;
	printf("Input the number of k: ");
	scanf("%d", &k);
	HPDataType* kminheap = (HPDataType*)malloc(sizeof(HPDataType) * k);
	if (kminheap == NULL) {
		perror("Malloc");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("FILE");
		return;
	}
	for (int i = 0;i < k;i++) {
		fscanf(fout,"%d", &kminheap[i]);
	}

	for (int i = (k - 2) / 2;i >= 0; i--) 
	{
		AdjustDown(kminheap, k, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x)!=EOF )
	{
		if (x > kminheap[0])
		{
			kminheap[0]= x;
			AdjustDown(kminheap, k, 0);
		}
	}

	for (int i = 0;i < k;i++) {
		printf("%d ", kminheap[i]);
	}
	fclose(fout);
}

//int main() {
//	//TestHeap01();
//	//CreateData();
//	TestHeap02();
//	return 0;
//}

//TRAVERSAL TESTING

typedef int BTDataType;
typedef struct BinaryTreeNode 
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

BTNode* BuyNode(BTDataType x) 
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL) {
		perror("Malloc fail");
		return;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* CreateBinaryTree() 
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	
	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL) {
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}

void InOrder(BTNode* root) 
{
	if (root == NULL)
	{
		printf("N ");
		
		return;
	}
	
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
	
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");

		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);

}

int TreeSize(BTNode* root) 
{
	/*return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;*/
	if (root == NULL) {
		return 0;
	}
	else 
	{
		return TreeSize(root->left) + TreeSize(root->right) + 1;
	}
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL) {
		return 0;
	}
	if (root->left == root->right == NULL) {
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root) 
{
	if (root == NULL) {
		return 0;
	}

	int leftHight = TreeHeight(root->left);
	int rightHight = TreeHeight(root->right);

	return leftHight > rightHight ?
		leftHight + 1 : rightHight + 1;
}
int main()
{
	BTNode* root = CreateBinaryTree();
	//PrevOrder(root);
	//InOrder(root);
	PostOrder(root);
	printf("\n");
	printf("TreeSize is %d.",TreeSize(root));
	return 0;
}
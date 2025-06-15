#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

BTNode* CreateBinaryTree() 
{

	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;
	/*BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	node1->left = node2;
	node1->right = node3;*/

	return node1;

}

int main()
{
	BTNode* root = CreateBinaryTree();
	/*PrevOrder(root);
	printf("\n");
	printf("The TreeSize is %d\n", TreeSize(root));
	printf("The TreeLeafSize if %d\n", TreeLeafSize(root));
	printf("The TreeHeight is %d\n", TreeHeight(root));
	int input = 0;
	printf("Input the level nums need to be calculate:->");
	scanf("%d", &input);
	printf("level %d's size is %d",input ,TreeLevelKSize(root, input));*/
	/*BTNode* res = TreeFind(root, 6);
	printf("%d\n", res->val);*/

	//TreeLevelOrder(root);
	TreeComplete(root);
	return 0;
}


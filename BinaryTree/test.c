#define _CRT_SECURE_NO_WARNINGS 1



#include "BinaryTree.h"

BTNode* CreateTree()
{
	BTNode* node1 = BTBuynode(1);
	BTNode* node2 = BTBuynode(2);
	BTNode* node3 = BTBuynode(3);
	BTNode* node4 = BTBuynode(4);
	BTNode* node5 = BTBuynode(5);
	BTNode* node6 = BTBuynode(6);


	node1->leftchild = node2;
	node1->rightchild = node4;
	node2->leftchild = node3;
	node4->leftchild = node5;
	node4->rightchild = node6;

	return node1;
}

int main()
{
	BTNode* root = CreateTree();
	Preorder(root);
	printf("\n");

	Inorder(root);
	printf("\n");

	Postorder(root);
	printf("\n");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1


#include "BinaryTree.h"

BTNode* BTBuynode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->leftchild = NULL;
	node->rightchild = NULL;

	return node;
}
void Preorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	Preorder(root->leftchild);
	Preorder(root->rightchild);

}

void Inorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	Inorder(root->leftchild);
	printf("%d ", root->data);
	Inorder(root->rightchild);
}

void Postorder(BTNode* root) 
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	Postorder(root->leftchild);
	Postorder(root->rightchild);
	printf("%d ", root->data);
}

BTNode* BTFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* lret = BTFind(root->leftchild, x);

	if (lret)
		return lret;

	BTNode* rret = BTFind(root->rightchild, x);
	if (rret)
		return rret;

	return NULL;
}

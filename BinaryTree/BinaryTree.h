#pragma once


#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* leftchild;
	struct BinaryTreeNode* rightchild;
	BTDataType data;

}BTNode;
BTNode* BTBuynode(BTDataType x);

void Preorder(BTNode* root);
void Inorder(BTNode* root);
void Postorder(BTNode* root);

BTNode* BTFind(BTNode* root, BTDataType x);

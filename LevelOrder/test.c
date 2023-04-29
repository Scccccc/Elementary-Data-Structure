#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
typedef int BTDatatype;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDatatype val;
}BTNode;



BTNode* BTBuynode(BTDatatype x)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	root->val = x;
	root->left = NULL;
	root->right = NULL;
	return root;
}

BTNode* CreateTree()
{
	BTNode* node1 = BTBuynode(1);
	BTNode* node2 = BTBuynode(2);
	BTNode* node3 = BTBuynode(3);
	BTNode* node4 = BTBuynode(4);
	BTNode* node5 = BTBuynode(5);
	BTNode* node6 = BTBuynode(6);
	BTNode* node7 = BTBuynode(7);



	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node2->right = node7;

	node4->left = node5;
	node4->right = node6;

	return node1;
}

void LevelOrder(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);

	if (root)
	{
		QueuePush(&pq, root);
	}

	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);

		printf("%d ", front->val);

		if (front->left)
			QueuePush(&pq, front->left);

		if (front->right)
			QueuePush(&pq, front->right);

	}

	QueueDestroy(&pq);

}

//判断一颗二叉树是否为完全二叉树
bool TreeCamplate(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);

	if (root)
	{
		QueuePush(&pq, root);
	}

	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);

		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&pq, front->left);
			QueuePush(&pq, front->right);
		}
	}

	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);
		//如果有非空 说明不是连续的
		if (front != NULL)
		{
			QueueDestroy(&pq);
			return false;
		}
	}
	QueueDestroy(&pq);
	return true;
	
}



int main()
{
	BTNode* root = CreateTree();
	LevelOrder(root);
	printf("\n");
	
	printf("%d\n", TreeCamplate(root));

	return 0;
}
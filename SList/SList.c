#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//打印
void SLTPrint(SListNode* phead)
{
	SListNode* cur = phead;

	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}

//创建新的节点
SListNode* BuySLTNode(SLTDataType x)
{
	SListNode* ret = (SListNode*)malloc(sizeof(SListNode));
	if (ret == NULL)
	{
		perror("BuySLTNode");
		return NULL;
	}
	ret->data = x;
	ret->next = NULL;

	return ret;
}

//尾插
void SLTPushBack(SListNode** pphead, SLTDataType x)
{
	SListNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* tail = *pphead;
		//找尾
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}

}

//头插
void SLTPushFront(SListNode** pphead, SLTDataType x)
{
	SListNode* newnode = BuySLTNode(x);
	SListNode* tail = *pphead;

	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SLTPopBack(SListNode** pphead)
{

	assert(*pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* tail = *pphead;

		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}

}

//头删
void SLTPopFront(SListNode** pphead)
{
	assert(*pphead != NULL);

	SListNode* tail = *pphead;
	*pphead = tail->next;
	free(tail);
	tail = NULL;

}
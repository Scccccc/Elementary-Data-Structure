#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		perror("BuySListNode");
		return NULL;
	}
	NewNode->data = x;
	NewNode->next = NULL;

	return NewNode;
}


void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* NewNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = NewNode;
	}
}


void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* NewNode = BuySListNode(x);
	NewNode->next = *pphead;
	*pphead = NewNode;
}


void SLTPopBack(SLTNode** pphead)
{
	//SLTNode* tail = *pphead; 
	//SLTNode* prev = NULL;
	//while (tail->next != NULL)
	//{
	//	prev = tail;
	//	tail = tail->next;
	//}
	//free(tail);
	//tail = NULL;

	//prev->next = NULL;
	assert(*pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}


void SLTPopFront(SLTNode** pphead)
{

	assert(*pphead != NULL);
	SLTNode* save = *pphead;

	*pphead = (*pphead)->next;
	free(save);
	save = NULL;

}

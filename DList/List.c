#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"
//创建新的节点
ListNode* BuyListNode(LDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("BuyListNode");
		return NULL;
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;

	return newnode;
}

//初始化头节点
ListNode* LsitInit()
{
	ListNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//打印节点数据
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;

	printf("head<=>");

	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//尾插
void ListPushback(ListNode* phead, LDataType x)
{
	assert(phead);

	/*ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/

	ListInsert(phead, x);

}

bool ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead;
}


//尾删
void ListPopback(ListNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	/*ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;
	
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;*/

	ListErase(phead->prev);

}

//头插
void ListPushFront(ListNode* phead, LDataType x)
{
	assert(phead);
	/*ListNode* newnode = BuyListNode(x);
	
	newnode->next = phead->next;
	phead->next->prev = newnode;
	newnode->prev = phead;
	phead->next = newnode;*/

	ListInsert(phead->next, x);

}

//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	/*ListNode* tail = phead->next;
	phead->next = tail->next;
	tail->next->prev = phead;
	free(tail);
	tail = NULL;*/

	ListErase(phead->next);

}

//在pos的前一个位置插入
void ListInsert(ListNode* pos, LDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;

	pos->prev = newnode;
	newnode->next = pos;
	prev->next = newnode;
	newnode->prev = prev;

}

//删除pos位置节点
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(!ListEmpty(pos));

	ListNode* prev = pos->prev;

	prev->next = pos->next;
	pos->next->prev = prev;
	free(pos);
	pos = NULL;
}


//查找
ListNode* ListFind(ListNode* phead, LDataType x)
{
	assert(phead);
	ListNode* cur = phead;
	while (cur->data != x)
	{
		cur = cur->next;
	}

	return cur;
}


void ListDestroy(ListNode** pphead)
{
	assert(pphead);

	ListNode* cur = *pphead;

	while (cur->next != *pphead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

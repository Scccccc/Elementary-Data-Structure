#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LDataType;

typedef struct ListNode
{
	LDataType data;
	struct ListNode* prev;
	struct ListNode* next;

}ListNode;
//初始化头节点
ListNode* LsitInit();
//销毁节点
void ListDestroy(ListNode** pphead);
//打印
void ListPrint(ListNode* phead);

bool ListEmpty(ListNode* phead);

//尾插
void ListPushback(ListNode* phead, LDataType x);
//尾删
void ListPopback(ListNode* phead);
//头插
void ListPushFront(ListNode* phead, LDataType x);
//头删
void ListPopFront(ListNode* phead);

//在pos的前一个位置插入
void ListInsert(ListNode* pos, LDataType x);

//删除pos位置节点
void ListErase(ListNode* pos);

//查找
ListNode* ListFind(ListNode* pHead, LDataType x);




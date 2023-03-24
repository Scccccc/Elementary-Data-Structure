#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

 typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

 //打印
 void SLTPrint(SLTNode* phead);
 //尾插
 void SLTPushBack(SLTNode** pphead, SLTDataType x);
 //头插
 void SLTPushFront(SLTNode** pphead, SLTDataType x);
 //尾删
 void SLTPopBack(SLTNode** pphead);
 //头删
 void SLTPopFront(SLTNode** pphead);

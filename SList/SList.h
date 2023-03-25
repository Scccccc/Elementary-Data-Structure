#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;

}SListNode;

//打印
void SLTPrint(SListNode* phead);
//尾插
void SLTPushBack(SListNode** pphead, SLTDataType x);
//头插
void SLTPushFront(SListNode** pphead, SLTDataType x);
//尾删
void SLTPopBack(SListNode** pphead);
//头删
void SLTPopFront(SListNode** pphead);


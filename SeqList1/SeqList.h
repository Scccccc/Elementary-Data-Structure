#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INIT_CAPACITY 4

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int sz;
	int capacity;
}SeqList;



//初始化
void SeqListInit(SeqList* ps);

//销毁
void SeqListDestroy(SeqList* ps);

//打印
void SeqListPrint(SeqList* ps);


//增删查改

void SeqListPushback(SeqList* ps, SLDataType x);

void SeqListPopback(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);
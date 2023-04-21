#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HpDatatype;

typedef struct Heap
{
	HpDatatype* data;
	int size;
	int capcity;
}Heap;

void HeapInit(Heap* php);
void HeapDestroy(Heap* php);
void HeapPush(Heap* php, HpDatatype x);
void HeapPop(Heap* php);
HpDatatype HeapTop(Heap* php);
bool HeapEmpty(Heap* php);
int HeapSize(Heap* php);



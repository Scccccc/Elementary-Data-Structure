#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

//初始化
void HeapInit(Heap* php)
{
	assert(php);

	php->data = (HpDatatype*)malloc(sizeof(HpDatatype) * 4);
	if (php->data == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->size = 0;
	php->capcity = 4;

}
//销毁堆
void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->data);
	php->data = 0;
	php->capcity = 0;

}
//交换两个数
void Swap(HpDatatype* p1, HpDatatype* p2)
{
	HpDatatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//向上调整
void AdjustUp(HpDatatype* a, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//插入
void HeapPush(Heap* php, HpDatatype x)
{
	assert(php);

	if (php->capcity == php->size)
	{
		HpDatatype* tmp = (HpDatatype*)realloc(php->data, sizeof(HpDatatype) * php->capcity * 2);
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		php->data = tmp;
		php->capcity *= 2;
	}
	php->data[php->size] = x;
	php->size++;

	AdjustUp(php->data, php->size-1);
}
//向下调整
void AdjustDown(HpDatatype* a, int n, int parent)
{
	int child = parent * 2 + 1;
	if (child+1 < n && a[child] < a[child + 1])
	{
		child++;
	}
	while (child < n)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//删除
void HeapPop(Heap* php)
{
	assert(php);
	//assert(!HeapEmpty(php->data));

	Swap(&php->data[0], &php->data[php->size - 1]);
	php->size--;
	AdjustDown(php->data, php->size, 0);
}
//返回堆顶
HpDatatype HeapTop(Heap* php)
{
	assert(php);

	return php->data[0];
}
//判空
bool HeapEmpty(Heap* php)
{
	assert(php);

	return php->size == 0;
}
//堆的大小
int HeapSize(Heap* php)
{
	return php->size;
}
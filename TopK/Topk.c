#define _CRT_SECURE_NO_WARNINGS 1

#include "Topk.h"

void AdjustDown(HpDatatype* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}

void Swap(HpDatatype* p1, HpDatatype* p2)
{
	HpDatatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//初始化
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("SeqListInit");
		return;
	}
	ps->sz = 0;
	ps->capacity = INIT_CAPACITY;
}

//销毁
void SeqListDestroy(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->sz = ps->capacity = 0;
}

//打印
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}



//尾插
void SeqListPushback(SeqList* ps, SLDataType x)
{
	if (ps->sz == ps->capacity)
	{
		//扩容
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if(tmp == NULL)
		{
			perror("SeqListPushback");
			return;
		}
		ps->a = tmp;
		ps->capacity = ps->capacity * 2;

	}

	ps->a[ps->sz] = x;
	ps->sz++;
}

//尾删
void SeqListPopback(SeqList* ps)
{
	assert(ps->sz > 0);
	//if (ps->sz == ps->capacity)
	//	return;

	ps->sz--;

}

////查
//int SeqListFind(SeqList* ps, SLDataType x)
//{
//
//}
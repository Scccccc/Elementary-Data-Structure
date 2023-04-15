#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void STInit(Stack* ps)
{
	assert(ps);

	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->data == NULL)
	{
		perror("STInit");
		return;
	}
	ps->capcity = 4;
	ps->top = 0;
}

void STDestroy(Stack* ps)
{
	assert(ps);

	free(ps->data);
	ps->data = NULL;
	ps->capcity = 0;
	ps->top = 0;
}

void STPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capcity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * ps->capcity * 2);
		if (tmp == NULL)
		{
			perror("STPush relloc fail");
			return;
		}
		ps->data = tmp;
		ps->capcity = ps->capcity * 2;

	}
	ps->data[ps->top] = x;
	ps->top++;
}

void STPop(Stack* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}

bool STEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

int STSize(Stack* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->top;

}

STDataType STTop(Stack* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->data[ps->top - 1];
}
#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void STInit(struct Stack* ps) 
{
	assert(ps);

	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	ps->capcity = 4;
	ps->top = 0;
}

void STDestroy(struct Stack* ps)
{
	assert(ps);

	free(ps->data);
	ps->data = NULL;
	ps->capcity = 0;
	ps->top = 0;
}

void STPush(struct Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capcity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->data, sizeof(STDataType) * ps->capcity * 2);
		if(tmp == NULL)
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

void STPop(struct Stack* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	ps->top--;
}

bool STEmpty(struct Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

int STSize(struct Stack* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->top;

}

STDataType STTop(struct Stack* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->data[ps->top - 1];
}




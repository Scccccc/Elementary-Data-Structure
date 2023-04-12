#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

typedef int STDataType;

struct Stack
{
	STDataType* data;
	int top;
	int capcity;
};

void STInit(struct Stack* ps);
void STDestroy(struct Stack* ps);

void STPush(struct Stack* ps, STDataType x);
void STPop(struct Stack* ps);

bool STEmpty(struct Stack* ps);
int STSize(struct Stack* ps);

STDataType STTop(struct Stack* ps);




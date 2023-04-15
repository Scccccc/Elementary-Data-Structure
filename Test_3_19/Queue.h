#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capcity;
}Stack;

typedef struct
{
	Stack st1;
	Stack st2;
} MyQueue;


void STInit(Stack* ps);
void STDestroy(Stack* ps);

void STPush(Stack* ps, STDataType x);
void STPop(Stack* ps);

bool STEmpty(Stack* ps);
int STSize(Stack* ps);

STDataType STTop(Stack* ps);
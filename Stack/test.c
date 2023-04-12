#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void Test1()
{
	struct Stack ST;
	STInit(&ST);

	STPush(&ST, 1);
	STPush(&ST, 2);
	STPop(&ST);

	STPush(&ST, 3);
	STPush(&ST, 4);
	STPop(&ST);

	STPush(&ST, 5);
	STPush(&ST, 6);


	while (!STEmpty(&ST))
	{
		printf("%d ", STTop(&ST));
		STPop(&ST);
	}

	STDestroy(&ST);
}

int main()
{
	Test1();
	return 0;
}
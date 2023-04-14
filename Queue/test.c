#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"


void Test()
{
	Queue st;
	QueueInit(&st);

	QueuePush(&st, 1);
	QueuePush(&st, 2);
	QueuePush(&st, 3);
	QueuePush(&st, 4);
	QueuePush(&st, 5);
	QueuePush(&st, 6);
	printf("%d ", QueueBack(&st));
	//while (!QueueEmpty(&st))
	//{
	//	printf("%d ", QueueBack(&st));
	//	QueuePop(&st);
	//}
	//printf("\n");

	QueueDestroy(&st);
}

int main()
{
	Test();
	return 0;
}
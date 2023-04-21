#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

void test()
{
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 12);
	HeapPush(&hp, 40);
	HeapPush(&hp, 35);
	HeapPush(&hp, 21);
	HeapPush(&hp, 5);
	HeapPush(&hp, 2);
	HeapPush(&hp, 1);
	HeapPush(&hp, 26);
	HeapPush(&hp, 18);
	//HeapPop(&hp);


	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);

}
int main()
{
	test();
	return 0;
}
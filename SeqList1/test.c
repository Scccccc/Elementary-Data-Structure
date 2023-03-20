#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void Test()
{
	SeqList ps;

	SeqListInit(&ps);

	SeqListPushback(&ps, 1);
	SeqListPushback(&ps, 2);
	SeqListPushback(&ps, 3);



	SeqListPrint(&ps);

	SeqListPopback(&ps);
	SeqListPopback(&ps);


	SeqListPrint(&ps);


	SeqListDestroy(&ps);

}

int main()
{
	Test();

	return 0;
}

//移除元素
//int removeElement(int* nums, int numsSize, int val) {
//
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != val)
//		{
//			nums[count] = nums[i];
//			count++;
//		}
//	}
//	return count;
//
//}
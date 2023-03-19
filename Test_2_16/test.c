#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//消失的数字 方法一：异或
//int missingNumber(int* nums, int numsSize) {
//
//    int val = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        val ^= nums[i];
//    }
//
//    for (i = 0; i < numsSize + 1; i++)
//    {
//        val ^= i;
//    }
//    return val;
//}

//方法二

int missingNumber(int* nums, int numsSize) {

    int sum = numsSize * (numsSize + 1) / 2;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        sum -= nums[i];
    }   
    return sum;
}
int main()
{
    int arr[] = { 0, 1, 3 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = missingNumber(arr, sz);
    printf("%d\n", ret);
    return 0;
}
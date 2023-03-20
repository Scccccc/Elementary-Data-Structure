#define _CRT_SECURE_NO_WARNINGS 1

//轮转数组
//void reverse(int* nums, int beging, int end)
//{
//    while (beging < end)
//    {
//        int tmp = nums[beging];
//        nums[beging] = nums[end];
//        nums[end] = tmp;
//
//        beging++;
//        end--;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k > numsSize)
//        k %= numsSize;
//
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//
//}

//轮转数组
//void rotate(int* nums, int numsSize, int k)
//{
//    if (k > numsSize)
//        k %= numsSize;
//
//    int* tmp = (int*)malloc(sizeof(nums) * numsSize);
//    memcpy(tmp, nums + numsSize - k, sizeof(nums) * k);
//    memcpy(tmp+k, nums, sizeof(nums) * numsSize-k);
//    memcpy(nums, tmp, sizeof(nums) * numsSize);
//
//}
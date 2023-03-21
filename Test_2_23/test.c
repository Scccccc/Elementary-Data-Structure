#define _CRT_SECURE_NO_WARNINGS 1

//删除有序数组的重复项
//int removeDuplicates(int* nums, int numsSize) {
//    int src = 1;
//    int dest = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != nums[dest])
//        {
//            nums[++dest] = nums[src++];
//        }
//        else
//        {
//            src++;
//        }
//
//    }
//    return dest + 1;
//}

//合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int end1 = m - 1;
    int end2 = n - 1;
    int dest = m + n - 1;

    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] > nums2[end2])
        {
            nums1[dest--] = nums1[end1--];
        }
        else
        {
            nums1[dest--] = nums2[end2--];
        }
    }

    while (end2 >= 0)
    {
        nums1[dest--] = nums2[end2--];
    }
}
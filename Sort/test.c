#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"


int main()
{
	int a[10] = { 9,8,7,5,4,2,6,3,1,0 };
	//InsertSort(a, 10);
	//PrintArray(a, 10);

	ShellSort(a, 10);
	PrintArray(a, 10);

	return 0;
}
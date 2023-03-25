#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"


void SListTest()
{
	SListNode* plist = NULL;
	/*SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);*/

	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);

	SLTPrint(plist);


}

int main()
{
	SListTest();
	return 0;
}
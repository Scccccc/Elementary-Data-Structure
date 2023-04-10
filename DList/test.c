#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void ListTest()
{
	ListNode* plist = LsitInit();

	ListPushback(plist, 1);
	ListPushback(plist, 2);
	ListPushback(plist, 3);
	ListPushback(plist, 4);

	ListPrint(plist);

	ListPopback(plist);
	ListPopback(plist);
	ListPopback(plist);
	ListPopback(plist);

	ListPrint(plist);

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);



}

void ListTest1()
{
	ListNode* plist = LsitInit();

	ListPushback(plist, 1);
	ListPushback(plist, 2);
	ListPushback(plist, 3);
	ListPushback(plist, 4);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);

	ListPrint(plist);

}

void ListTest2()
{
	ListNode* plist = LsitInit();

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);

	ListPushback(plist, 1);
	ListPushback(plist, 2);
	ListPushback(plist, 3);
	ListPushback(plist, 4);

	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopback(plist);
	ListPopback(plist);
	ListPopback(plist);
	ListPopback(plist);


	ListPrint(plist);
}

void ListTest3()
{
	ListNode* plist = LsitInit();


	ListPushback(plist, 1);
	ListPushback(plist, 2);
	ListPushback(plist, 3);
	ListPushback(plist, 4);
	ListPrint(plist);


	ListNode* ret = ListFind(plist, 2);
	printf("%d\n", ret->data);

	ListDestroy(&plist);

}

int main()
{
	ListTest3();
	return 0;
}
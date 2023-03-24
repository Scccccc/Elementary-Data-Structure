#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"


void TestSList1()
{
	SLTNode* Plist = NULL;
	SLTPushBack(&Plist, 1);
	SLTPushBack(&Plist, 2);
	SLTPushBack(&Plist, 3);
	SLTPushBack(&Plist, 4);

	SLTPrint(Plist);

}

void TestSList2()
{
	SLTNode* Plist = NULL;
	SLTPushFront(&Plist, 1);
	SLTPushFront(&Plist, 2);
	SLTPushFront(&Plist, 3);
	SLTPushFront(&Plist, 4);
	SLTPrint(Plist);

	SLTPopFront(&Plist);
	SLTPrint(Plist);

	SLTPopFront(&Plist);
	SLTPrint(Plist);


	SLTPopFront(&Plist);
	SLTPrint(Plist);

	SLTPopFront(&Plist);
	SLTPrint(Plist);

}

int main()
{
	TestSList2();
	return 0;
}
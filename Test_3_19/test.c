#define _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"


////用队列实现栈
//typedef int QDatatype;
//
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDatatype data;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
//typedef struct
//{
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//
//
//void QueueInit(Queue* pq);
//void QueueDestroy(Queue* pq);
//
//void QueuePush(Queue* pq, QDatatype x);
//void QueuePop(Queue* pq);
//int QueueSize(Queue* pq);
//bool QueueEmpty(Queue* pq);
//QDatatype QueueFront(Queue* pq);
//QDatatype QueueBack(Queue* pq);
//
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->head = NULL;
//	pq->tail = NULL;
//	pq->size = 0;
//
//}
//
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//	pq->size = 0;
//}
//
//void QueuePush(Queue* pq, QDatatype x)
//{
//	assert(pq);
//
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->tail == NULL)
//	{
//		assert(pq->tail == NULL);
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//
//	pq->size++;
//
//}
//
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	if (pq->head == pq->tail)
//	{
//		free(pq->head);
//		pq->head = NULL;
//		pq->tail = NULL;
//	}
//	else
//	{
//		QNode* del = pq->head;
//		QNode* next = pq->head->next;
//		free(del);
//		del = NULL;
//		pq->head = next;
//	}
//
//	pq->size--;
//
//}
//
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//
//	return pq->size;
//}
//
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//
//	return pq->head == NULL && pq->tail == NULL;
//}
//
//QDatatype QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->head->data;
//}
//
//QDatatype QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//
//	return pq->tail->data;
//}
//
//
//
//
//
//MyStack* myStackCreate()
//{
//	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//	if (pst == NULL)
//	{
//		perror("malloc fail");
//		return NULL;
//	}
//
//	QueueInit(&pst->q1);
//	QueueInit(&pst->q2);
//
//	return pst;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj)
//{
//	Queue* Empty = &obj->q1;
//	Queue* NoneEmpty = &obj->q2;
//	if (!QueueEmpty(Empty))
//	{
//		Empty = &obj->q2;
//		NoneEmpty = &obj->q1;
//	}
//	while (QueueSize(NoneEmpty) > 1)
//	{
//		QueuePush(Empty, QueueFront(NoneEmpty));
//		QueuePop(NoneEmpty);
//	}
//	int top = QueueBack(NoneEmpty);
//	QueuePop(NoneEmpty);
//	return top;
//
//}
//
//int myStackTop(MyStack* obj)
//{
//	if (!QueueEmpty(&obj->q1))  
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//}


//用栈实现队列
MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if (obj == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    STInit(&obj->st1);
    STInit(&obj->st2);

    return obj;

}

void myQueuePush(MyQueue* obj, int x)
{
    STPush(&obj->st1, x);
}

int myQueuePeek(MyQueue* obj)
{
    if (STEmpty(&obj->st2))
    {
        while (!STEmpty(&obj->st1))
        {
            STPush(&obj->st2, STTop(&obj->st1));
            STPop(&obj->st1);
        }
    }
    int top = STTop(&obj->st2);
    return top;
}

int myQueuePop(MyQueue* obj)
{
    int pop = myQueuePeek(obj);
    STPop(&obj->st2);
    return pop;
}

bool myQueueEmpty(MyQueue* obj)
{
    return STEmpty(&obj->st1) && STEmpty(&obj->st2);
}

void myQueueFree(MyQueue* obj)
{
    STDestroy(&obj->st1);
    STDestroy(&obj->st2);
    free(obj);
}

int main()
{
    MyQueue* st = myQueueCreate();
    myQueuePush(st, 1);
    myQueuePush(st, 2);
    myQueuePush(st, 3);
    while (!myQueueEmpty(st))
    {
        int ret = myQueuePop(st);
        printf("%d", ret);

    }


    return 0;
}
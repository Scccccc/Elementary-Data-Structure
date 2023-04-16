#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"
//初始化
MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    obj->k = k;
    obj->data = (int*)malloc(sizeof(int) * (obj->k + 1));
    if (obj->data == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    obj->front = 0;
    obj->rear = 0;

    return obj;
}

//判空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    assert(obj);
    return obj->front == obj->rear;
}

//判满
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}
//队尾插入
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        obj->data[obj->rear++] = value;
        obj->rear %= (obj->k + 1);
        return true;
    }

}
//队头删除
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        obj->front++;
        obj->front %= (obj->k + 1);
        return true;
    }
}
//返回队头的值
int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->data[obj->front];
}
//返回队尾的值
int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        //队头如果在0的位置上，减1会到-1的位置上
        //假设k = 4，         -1      +        5       %      5
        return obj->data[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
}


//释放
void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->data);
    free(obj);
    obj = NULL;
}
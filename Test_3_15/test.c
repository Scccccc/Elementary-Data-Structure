#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)
    {
        //在原节点后插入插入新的节点
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        struct Node* next = cur->next;

        copy->val = cur->val;

        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    //拷贝原链表的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    //链接拷贝的节点，并恢复原链表
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (copyhead == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;

        }
        cur->next = copy->next;
        cur = cur->next;
    }

    return copyhead;




}
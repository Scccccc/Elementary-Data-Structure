#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>

//移除链表元素1
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* newhead = NULL, * tail = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        if (cur->val != val)
        {
            if (tail == NULL)
            {
                newhead = tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }

            cur = cur->next;
        }
        else
        {
            struct ListNode* next = cur->next;
            free(cur);
            cur = next;
        }
    }

    if (tail)
        tail->next = NULL;

    return newhead;
}



//移除链表元素2

 struct ListNode* removeElements(struct ListNode* head, int val)
 {
     struct ListNode* prev = NULL;
     struct ListNode* cur = head;

     while(cur)
     {
         if(cur->val != val)
         {
             prev = cur;
             cur = cur->next;
         }
         else
         {
             if(prev == NULL)
             {
                 head = cur->next;
                 free(cur);
                 cur = head;
             }
             else
             {
                 prev->next = cur->next;
                 free(cur);
                 cur = prev->next;
             }

         }
     }
     return head;
 }

 //链表的中间结点
 struct ListNode* middleNode(struct ListNode* head)
 {
     struct ListNode* slow, * fast;
     slow = fast = head;

     while (fast && fast->next)
     {
         slow = slow->next;
         fast = fast->next->next;
     }
     return slow;
 }

 //链表中返回倒数k的节点
 struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
     struct ListNode* slow, * fast;
     slow = fast = pListHead;
     while (--k)
     {
         if (fast == NULL)
             return NULL;

         fast = fast->next;

     }
     while (fast->next && fast != NULL)
     {
         slow = slow->next;
         fast = fast->next;
     }

     if (fast == NULL)
         return NULL;

     return slow;
 }

#define _CRT_SECURE_NO_WARNINGS 1


// struct ListNode* reverseList(struct ListNode* head)
// {
//     struct ListNode* cur = head;
//     struct ListNode* newhead = NULL;
//     while(cur)
//     {
//         struct ListNode* next = cur->next;
//         cur->next = newhead;

//         newhead = cur;

//         cur = next;

//     }
//     return newhead;
// }

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;

    while (cur)
    {
        cur->next = prev;

        prev = cur;
        cur = next;
        if (next)
            next = cur->next;
    }

    return prev;
}


// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
//     if(list1 == NULL)
//         return list2;
//     if(list2 == NULL)
//         return list1;
//     struct ListNode* cur1 = list1;
//     struct ListNode* cur2 = list2;
//     struct ListNode* newhead = NULL, *tail = NULL;

//     while(cur1 && cur2)
//     {
//         if(cur1->val < cur2->val)
//         {
//             if(newhead == NULL)
//             {
//                 newhead = tail = cur1;
//             }
//              else
//             {
//                 tail->next = cur1;
//                 tail = cur1;
//             }
//             cur1 = cur1->next;
//         }
//         else
//         {
//             if(newhead == NULL)
//             {
//                 newhead = tail = cur2;
//             }
//              else
//             {
//                 tail->next = cur2;
//                 tail = cur2;
//             }
//             cur2 = cur2->next;
//         }

//     }
//     if(cur1)
//         tail->next = cur1;
//     if(cur2)
//         tail->next = cur2;

//     return newhead;
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    struct ListNode* guard = NULL, * tail = NULL;
    guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;

    while (cur1 && cur2)
    {
        if (cur1->val < cur2->val)
        {
            tail->next = cur1;
            tail = cur1;
            cur1 = cur1->next;
        }
        else
        {
            tail->next = cur2;
            tail = cur2;
            cur2 = cur2->next;
        }

    }
    if (cur1)
        tail->next = cur1;
    if (cur2)
        tail->next = cur2;

    struct ListNode* newhead = guard->next;
    free(guard);
    return newhead;
}

//链表分割
class Partition
{
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        ListNode* lessguard, * lesstail, * greatguard, * greattail;
        lessguard = lesstail = (ListNode*)malloc(sizeof(ListNode));
        greatguard = greattail = (ListNode*)malloc(sizeof(ListNode));
        lesstail->next = NULL;
        greattail->next = NULL;

        ListNode* cur = pHead;

        while (cur)
        {
            if (cur->val < x)
            {
                lesstail->next = cur;
                lesstail = lesstail->next;
            }
            else
            {
                greattail->next = cur;
                greattail = greattail->next;
            }
            cur = cur->next;
        }
        greattail->next = NULL;
        lesstail->next = greatguard->next;

        pHead = lessguard->next;
        free(lessguard);
        free(greatguard);
        return pHead;
    }
};

//链表的回文结构
class PalindromeList {
public:
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

    struct ListNode* reverseList(struct ListNode* head)
    {
        if (head == NULL)
            return NULL;
        struct ListNode* prev = NULL;
        struct ListNode* cur = head;
        struct ListNode* next = cur->next;

        while (cur)
        {
            cur->next = prev;

            prev = cur;
            cur = next;
            if (next)
                next = cur->next;
        }

        return prev;
    }
    bool chkPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* phead = reverseList(mid);

        while (head && phead)
        {
            if (head->val != phead->val)
            {
                return false;
            }

            head = head->next;
            phead = phead->next;
        }
        return true;
    }
};


//链表相交
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int lenA = 1, lenB = 1;
    while (tailA->next)
    {
        tailA = tailA->next;
        lenA++;
    }

    while (tailB->next)
    {
        tailB = tailB->next;
        lenB++;
    }
    if (tailA != tailB)
        return NULL;

    int gap = abs(lenA - lenB);

    struct ListNode* Longlist = headA, * Shortlist = headB;
    if (lenA < lenB)
    {
        Longlist = headB;
        Shortlist = headA;
    }

    while (gap--)
    {
        Longlist = Longlist->next;
    }

    while (Longlist != Shortlist)
    {
        Longlist = Longlist->next;
        Shortlist = Shortlist->next;
    }
    return Longlist;


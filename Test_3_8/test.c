#define _CRT_SECURE_NO_WARNINGS 1

//环形链表判断
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

//返回环形链表入环的第一个节点

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            struct ListNode* meet = slow;
            struct ListNode* start = head;
            while (meet != start)
            {
                start = start->next;
                meet = meet->next;
            }
            return meet;
        }

    }
    return NULL;
}
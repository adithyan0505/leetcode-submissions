/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    struct ListNode *begin = NULL;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if(fast == slow)
        {
            fast = head;
            while(fast!=slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            begin = slow;
            break;
        }
    }
    return begin;
}
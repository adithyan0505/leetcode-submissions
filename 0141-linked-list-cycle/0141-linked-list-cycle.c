/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    int cycle = false;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if(fast == slow)
        {
            cycle = true;
            break;
        }
    }
    return cycle;
}
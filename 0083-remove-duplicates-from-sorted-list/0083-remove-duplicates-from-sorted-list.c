/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    while(curr && curr->next)
    {
        while(curr->next && curr->next->val == curr->val)
        {
            struct ListNode* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        curr = curr->next;
    }
    return head;
}
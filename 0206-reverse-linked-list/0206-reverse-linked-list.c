/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head)
        return NULL;
    struct ListNode* next = head->next;
    struct ListNode* prev = NULL;
    while(next){
        head->next = prev;
        prev = head;
        head = next;
        next = head->next;
    }
    head->next=prev;
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* tail = head;
    if (head) {
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        while (k--) {
            tail->next = head;
            struct ListNode* temp = head;
            while (temp->next != tail)
                temp = temp->next;
            temp->next = NULL;
            head = tail;
            tail = temp;
        }
    }
    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p0=head, *p1=head;
    for(int i = 0;i < n;i++)
        p1 = p1->next;
    while(p1 && p1->next)
    {
        p1 = p1->next;
        p0 = p0->next;
    }
    if(p1==NULL){
        head = p0->next;
        free(p0);
    }
    else{
        struct ListNode* temp = p0->next;
        p0->next = temp->next;
        free(temp);     
    }
    return head;   
}
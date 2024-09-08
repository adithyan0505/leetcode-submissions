/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    *returnSize = k;
    struct ListNode** ret = (struct ListNode**)malloc(k*sizeof(struct ListNode*));
    int len = 0; struct ListNode* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    int q = len/k, r = len%k;
    for(int i=0;i<k;i++){
        ret[i] = NULL;
        struct ListNode* part;
        for(int j=0;j<q;j++){
            if(head!=NULL){
                part = (struct ListNode*)malloc(sizeof(struct ListNode));
                part->next = NULL;
                if(ret[i]==NULL){
                    part->val = head->val;
                    ret[i] = part;
                    temp = ret[i];
                    head = head->next;
                }else{
                    part->val = head->val;
                    temp->next = part;
                    temp = temp->next;
                    head = head->next;
                }
            }else break;
        }
        if(i < r){
            part = (struct ListNode*)malloc(sizeof(struct ListNode));
            part->next = NULL;
            if(ret[i]==NULL){
                part->val = head->val;
                ret[i] = part;
                temp = ret[i];
                head = head->next;
            }else{
                part->val = head->val;
                temp->next = part;
                temp = temp->next;
                head = head->next;
            }
        }
    }
    return ret;
}
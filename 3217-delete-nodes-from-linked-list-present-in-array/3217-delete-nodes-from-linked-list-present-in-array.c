/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int hash[100001] = {0};
    for(int i=0;i < numsSize;i++)
        hash[nums[i]] = 1;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while(curr){
        if(hash[curr->val]){
            if(!prev){
                head = head->next;
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp);
            }else{
                prev->next = curr->next;
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp);
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
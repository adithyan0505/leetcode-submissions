/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(!head1 || !head2){
            return (!head1 ? head2:head1);
        }
        ListNode *h1 = head1->val < head2->val ? head1:head2;
        ListNode *h2 = h1==head1 ? head2:head1;
        ListNode *prev = NULL;
        while(h1 && h2){
            if(h1->val <= h2->val){
                prev = h1;
                h1 = h1->next;
            }else{
                prev->next = h2;
                h2 = h2->next;
                prev->next->next = h1;
                prev = prev->next;
            }
        }
        if(h2 != NULL){
            prev->next = h2;
        }
        return (head1->val < head2->val ? head1:head2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = NULL;
        int n = lists.size();
        for(int i=0;i<n;i++){
            node = mergeTwoLists(node, lists[i]);
        }
        return node;
    }
};
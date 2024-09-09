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
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int rstart = 0, rend = m-1;
        int cstart = 0, cend = n-1;
        while(head){
            for(int j=cstart;j<=cend;j++){
                if(head){
                    matrix[rstart][j] = head->val;
                    head = head->next;
                }
            }rstart++;
            for(int i=rstart;i<=rend;i++){
                if(head){
                    matrix[i][cend] = head->val;
                    head = head->next;
                }
            }cend--;
            for(int j=cend;j>=cstart;j--){
                if(head){
                    matrix[rend][j] = head->val;
                    head = head->next;
                }
            }rend--;
            for(int i=rend;i>=rstart;i--){
                if(head){
                    matrix[i][cstart] = head->val;
                    head = head->next;
                }
            }cstart++;
        }
        return matrix;
    }
};
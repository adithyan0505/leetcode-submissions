/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool DFS(struct ListNode* head, struct TreeNode* root){
    if(root!=NULL && head != NULL){
        if(head->val == root->val)
            return (DFS(head->next,root->left) || DFS(head->next,root->right));
    }
    if(head == NULL)
        return true;
    return false;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if(root==NULL)
        return false;
    if (head->val == root->val && DFS(head,root))
        return true;
    return (isSubPath(head,root->left) || isSubPath(head,root->right));
}
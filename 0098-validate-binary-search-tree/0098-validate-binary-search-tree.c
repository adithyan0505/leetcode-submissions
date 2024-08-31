/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool helper(struct TreeNode* root,long long int min,long long int max){
    if(root){
        if(root->val <= min || root->val >= max)
            return false;
        return (helper(root->left,min,root->val) && 
                helper(root->right,root->val,max));
    }
    return true;
}

bool isValidBST(struct TreeNode* root) {
    return helper(root,LLONG_MIN,LLONG_MAX);
}
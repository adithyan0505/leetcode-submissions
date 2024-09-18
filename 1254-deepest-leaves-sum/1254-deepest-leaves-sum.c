/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root){
    if(root==NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh > rh)
        return lh + 1;
    return rh + 1;
}

void helper(struct TreeNode* root,int level,int depth,int* sum){
    if(root==NULL)
        return;
    if(level==depth)
        (*sum) += root->val;
    helper(root->left,level+1,depth,sum);
    helper(root->right,level+1,depth,sum);
}

int deepestLeavesSum(struct TreeNode* root) {
    int sum = 0;
    int depth = height(root)-1;
    helper(root,0,depth,&sum);
    return sum;
}
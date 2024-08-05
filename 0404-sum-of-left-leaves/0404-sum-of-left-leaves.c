/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int sum = 0;
    if(root->left && (root->left)->right == NULL && (root->left)->left==NULL)
        sum += (root->left)->val;
    sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    return sum;
}
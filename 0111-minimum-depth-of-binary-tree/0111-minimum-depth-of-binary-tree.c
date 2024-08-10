/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    if((lh < rh) && lh)
        return lh + 1;
    else if((lh > rh) && rh)
        return rh + 1;
    else if (lh)
        return lh + 1;
    else
        return rh + 1;
}
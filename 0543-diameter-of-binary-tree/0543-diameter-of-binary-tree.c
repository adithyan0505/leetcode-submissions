/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Diameter(struct TreeNode* root,int* d)
{
    if(root == NULL)
        return 0;
    int lh = Diameter(root->left,d);
    int rh = Diameter(root->right,d);
    if(*d < lh+rh)
        *d = lh+rh;
    if(lh > rh)
        return 1 + lh;
    else
        return 1 + rh;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int dia=0;
    Diameter(root,&dia);
    return dia;
}
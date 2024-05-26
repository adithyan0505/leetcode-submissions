/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* node,int* arr,int* size)
{
    if(node==NULL) return;
    inorder(node->left,arr,size);
    arr[(*size)++] = node->val;
    inorder(node->right,arr,size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* arr = (int*)malloc(100*sizeof(int));
    inorder(root,arr,returnSize);
    return arr;
}
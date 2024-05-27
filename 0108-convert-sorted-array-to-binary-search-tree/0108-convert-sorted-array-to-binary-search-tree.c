/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int size) {
    if (size == 0)
        return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (size - 1) / 2;
    node->val = nums[mid];
    node->left = sortedArrayToBST(nums, mid);
    node->right = sortedArrayToBST(nums + mid + 1, size - mid - 1);
    return node;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->right = node->left = NULL;
    return node;
}

int findPos(int* arr, int size, int key) {
    int index;
    for (index = 0; index < size; index++) {
        if (arr[index] == key)
            break;
    }
    return index;
}

struct TreeNode* buildTree(int* pre, int preSize, int* in, int inSize) {
    struct TreeNode* root = newNode(pre[0]);
    int index = findPos(in, inSize, pre[0]);
    if (index)
        root->left = buildTree(pre + 1, preSize - 1, in, index);
    if (inSize - index - 1)
        root->right = buildTree(pre + index + 1, preSize - index - 1, in + index + 1, inSize - index - 1);
    return root;
}
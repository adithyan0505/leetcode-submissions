/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* temp =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < preorderSize; i++)
        root = insertIntoBST(root, preorder[i]);
    return root;
}
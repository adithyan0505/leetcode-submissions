/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* findParent(struct TreeNode* root, int val) {
    if (!root)
        return NULL;
    if (root->left) {
        if (root->left->val == val)
            return root;
    }
    if (root->right) {
        if (root->right->val == val)
            return root;
    }
    struct TreeNode* lparent = findParent(root->left, val);
    if (lparent)
        return lparent;
    return findParent(root->right, val);
}

int findLevel(struct TreeNode* root, int val, int level) {
    if (!root)
        return -1;
    if (root->val == val)
        return level;
    int llevel = findLevel(root->left, val, level + 1);
    if (llevel != -1)
        return llevel;
    return findLevel(root->right, val, level + 1);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    struct TreeNode* xparent = findParent(root, x);
    struct TreeNode* yparent = findParent(root, y);
    int xlevel = findLevel(root, x, 0);
    int ylevel = findLevel(root, y, 0);
    if (xlevel == ylevel) {
        if (xparent != yparent)
            return true;
    }
    return false;
}
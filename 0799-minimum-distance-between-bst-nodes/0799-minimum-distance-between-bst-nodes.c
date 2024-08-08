/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* successor(struct TreeNode* root,struct TreeNode* node)
{
    struct TreeNode* succ = NULL;
    while(root)
    {
        if(root->val > node->val)
        {
            succ = root;
            root = root->left;
        }
        else if(root->val < node->val)
            root = root->right;
        else
        {
            if(root->right)
            {
                succ = root->right;
                while(succ->left)
                    succ = succ->left;
                break;
            }
            else
                break;
        }
    }
    return succ;
}

int minDiffInBST(struct TreeNode* root) {
    int min = 100000, diff;
    struct TreeNode* temp = root;
    while(temp->left)
        temp = temp->left;
    struct TreeNode* succ = successor(root,temp);
    while(succ!=NULL)
    {
        diff = succ->val - temp->val;
        if(diff < min)
            min = diff;
        temp = succ;
        succ = successor(root,temp);
    }
    return min;
}
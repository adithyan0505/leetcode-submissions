/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* minimum(struct TreeNode* root)
{
    while(root->left != NULL)
    root = root->left;
    return root;
}

struct TreeNode* successor(struct TreeNode* root,int key)
{
    struct TreeNode* succ = NULL;
    while(root!=NULL)
    {
        if(root->val == key)
        {
            if(root->right!=NULL)
            {
               return minimum(root->right);
            }
            else
            {
                return succ;
            }
        }
        else if(root->val > key)
        {
            succ = root;
            root = root->left;
        }
        else root = root->right;
    }
    return NULL;
}

int maximum(struct TreeNode* root)
{
    while(root->right!=NULL)
    root = root->right;
    return root->val;
}

int getMinimumDifference(struct TreeNode* root) {
    int min_diff=100000;
    struct TreeNode* succ;
    struct TreeNode* temp = minimum(root);
    while(temp->val != maximum(root))
    {
        succ = successor(root,temp->val);
        int diff = (succ->val) - (temp->val);
        if(diff < min_diff)
        min_diff = diff;
        temp = succ;
    }
    return min_diff;
}
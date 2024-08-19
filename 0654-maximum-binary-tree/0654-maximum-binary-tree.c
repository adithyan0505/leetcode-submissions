/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findMax(int* arr,int size,int* index)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            (*index) = i;
        }
    }
    return max;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if(numsSize == 0)
        return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int maxI = 0;
    node->val = findMax(nums,numsSize,&maxI);
    node->left = constructMaximumBinaryTree(nums, maxI);
    node->right = constructMaximumBinaryTree(nums+maxI+1, numsSize-maxI-1);
    return node;
}
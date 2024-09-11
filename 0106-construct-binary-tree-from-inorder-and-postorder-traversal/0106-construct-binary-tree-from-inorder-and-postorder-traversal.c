/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* NewNode(int val){
    struct TreeNode* New = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    New->left = New->right = NULL;
    New->val = val;
    return New;
}

int FindIndex(int* arr,int size,int k){
    int ind;
    for(ind=0;ind<size;ind++){
        if(arr[ind] == k)
            break;
    }
    return ind;
}

struct TreeNode* buildTree(int* inorder, int insize, int* postorder, int psize) {
    int val = postorder[psize-1];
    struct TreeNode* node = NewNode(val);
    int index = FindIndex(inorder,insize,val);
    if(insize-index-1){
        int rightSubtreeSize = insize-index-1;
        node->right = buildTree(inorder+index+1,insize-index-1,postorder+index,insize-index-1);
    }
    if(index){
        int leftSubtreeSize = index;
        node->left = buildTree(inorder,leftSubtreeSize,postorder,leftSubtreeSize);
    }
    return node;
}
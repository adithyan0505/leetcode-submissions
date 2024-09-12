/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    typedef struct TreeNode* Node;
    int** array = (int**)malloc(2000*sizeof(int*));
    Node Q[2000];
    int front = 0, rear = 0;
    if(root) Q[rear++] = root;
    int level = 0;
    *returnColumnSizes = (int*)malloc(2000*sizeof(int));
    while(front < rear){
        int size = rear - front;
        (*returnColumnSizes)[level] = size;
        for(int i=0;i<size;i++){
            Node node = Q[front++];
            if(i==0){
                int* sub = (int*)malloc(size*sizeof(int));
                sub[0] = node->val;
                array[level] = sub;
            }
            else 
                array[level][i] = node->val; 
            if(node->left)
                Q[rear++] = node->left;
            if(node->right)
                Q[rear++] = node->right;
        }
        level++;
    }
    *returnSize = level;
    int** ret = (int**)malloc(2000*sizeof(int*));
    for(int i=level-1;i>=0;i--){
        ret[level-1-i] = (int*)malloc((*returnColumnSizes)[i]*sizeof(int));
        for(int j=0;j<(*returnColumnSizes)[i];j++)
            ret[level-1-i][j] = array[i][j];
    }
    for(int i=0;i<level/2;i++){
        int temp = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[level-1-i];
        (*returnColumnSizes)[level-1-i] = temp;
    }
    return ret;
}
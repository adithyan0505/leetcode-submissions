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
struct QNode{
    struct TreeNode* node;
    struct QNode* next;
};

struct Queue{
    struct QNode* front;
    struct QNode* rear;
};

void enqueue(struct Queue* q,struct TreeNode* n)
{
    struct QNode* qnode = (struct QNode*)malloc(sizeof(struct QNode));
    qnode->node = n;
    qnode->next = NULL;
    if(q->front == NULL)
        q->front = q->rear = qnode;
    else
    {
        q->rear->next = qnode;
        q->rear = qnode;
    }
}

struct TreeNode* dequeue(struct Queue* q)
{
    if(q->front == NULL)
        return NULL;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    struct TreeNode* node = temp->node;
    free(temp);
    return node;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double* ret = (double*)malloc(10000*sizeof(double));
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    enqueue(q,root);
    int level = 0, size = 1;
    while(q->front)
    {
        int n = size;
        double avg = 0;
        for(int i = 0;i < n;i++)
        {
            struct TreeNode* node = dequeue(q);
            size--;
            avg += node->val;
            if(node->left)
            {
                enqueue(q,node->left);
                size++;
            }
            if(node->right)
            {
                enqueue(q,node->right);
                size++;
            }
        }
        avg = avg/n;
        ret[level++] = avg;
    }
    *returnSize = level;
    return ret;
}
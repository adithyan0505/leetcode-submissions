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
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
struct QNode {
    struct TreeNode* node;
    struct QNode* next;
};

struct Queue {
    struct QNode* front;
    struct QNode* rear;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QNode* new = (struct QNode*)malloc(sizeof(struct QNode));
    new->node = node;
    new->next = NULL;
    if (q->front == NULL)
        q->front = q->rear = new;
    else {
        (q->rear)->next = new;
        q->rear = new;
    }
}

struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = temp->next;
    free(temp);
    return node;
}

int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    int h = height(root);
    int** array = (int**)malloc(h * sizeof(int*));
    *returnSize = h;
    *returnColumnSizes = (int*)malloc(h * sizeof(int));
    int index = 0;
    enqueue(q, root);
    int size = 1;
    while (q->front != NULL) {
        int* arr = (int*)malloc(size * sizeof(int));
        int n = size;
        for (int i = 0; i < n; i++) {
            struct TreeNode* node = dequeue(q);
            size--;
            if (node->left) {
                enqueue(q, node->left);
                size++;
            }
            if (node->right) {
                enqueue(q, node->right);
                size++;
            }
            arr[i] = node->val;
        }
        array[index] = arr;
        (*returnColumnSizes)[index++] = n;
    }
    return array;
}
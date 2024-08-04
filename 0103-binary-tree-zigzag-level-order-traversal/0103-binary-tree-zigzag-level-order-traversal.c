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

struct Stack {
    struct QNode* top;
};

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->node = node;
    newNode->next = NULL;
    if (q->front == NULL)
        q->front = q->rear = newNode;
    else {
        (q->rear)->next = newNode;
        q->rear = newNode;
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

void push(struct Stack* s, struct TreeNode* node) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->next = s->top;
    newNode->node = node;
    s->top = newNode;
}

struct TreeNode* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;
    struct QNode* temp = stack->top;
    struct TreeNode* node = temp->node;
    stack->top = (stack->top)->next;
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

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    int h = height(root);
    int** array = (int**)malloc(h * sizeof(int*));
    *returnSize = h;
    *returnColumnSizes = (int*)malloc(h * sizeof(int));
    int index = 0;
    enqueue(q, root);
    struct TreeNode* node;
    int size = 1, level = 0;
    while (q->front != NULL) {
        int* arr = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[index] = size;
        int i = 0;
        while (size) {
            node = dequeue(q);
            size--;
            arr[i++] = node->val;
            if (level % 2 == 0) {
                if (node->left)
                    push(s, node->left);
                if (node->right)
                    push(s, node->right);
            } else {
                if (node->right)
                    push(s, node->right);
                if (node->left)
                    push(s, node->left);
            }
        }
        while (s->top) {
            size++;
            enqueue(q, pop(s));
        }
        level++;
        array[index++] = arr;
    }
    free(s);
    free(q);
    return array;
}
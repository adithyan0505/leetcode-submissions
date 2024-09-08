/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct AVL {
    struct TreeNode* node;
    struct AVL* left;
    struct AVL* right;
    int height;
}* avl_node;

int height(avl_node avl) {
    if (avl == NULL)
        return -1;
    return avl->height;
}

int max(int a, int b) { return ((a > b) ? a : b); }

avl_node newNode(int val) {
    struct TreeNode* new_node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = new_node->right = NULL;
    avl_node New = (avl_node)malloc(sizeof(struct AVL));
    New->node = new_node;
    New->left = New->right = NULL;
    New->height = 0;
    return New;
}

avl_node rightRotate(avl_node avl_root) {
    avl_node new_root = avl_root->left;
    struct TreeNode* new = new_root->node;
    avl_root->left = new_root->right;
    avl_root->node->left = new->right;
    new_root->right = avl_root;
    new->right = avl_root->node;

    avl_root->height = max(height(avl_root->left), height(avl_root->right)) + 1;
    new_root->height = max(height(new_root->left), height(avl_root->right)) + 1;

    return new_root;
}

avl_node leftRotate(avl_node avl_root) {
    avl_node new_root = avl_root->right;
    struct TreeNode* new = new_root->node;
    avl_root->right = new_root->left;
    avl_root->node->right = new->left;
    new_root->left = avl_root;
    new->left = avl_root->node;

    avl_root->height = max(height(avl_root->left), height(avl_root->right)) + 1;
    new_root->height = max(height(new_root->left), height(avl_root->right)) + 1;

    return new_root;
}

int getBalance(avl_node avl_root) {
    return (height(avl_root->left) - height(avl_root->right));
}

avl_node Insert(avl_node avl_root, int val) {
    if (avl_root == NULL)
        return newNode(val);
    else if (avl_root->node->val > val) {
        avl_root->left = Insert(avl_root->left, val);
        avl_root->node->left = avl_root->left->node;
    } else if (avl_root->node->val < val) {
        avl_root->right = Insert(avl_root->right, val);
        avl_root->node->right = avl_root->right->node;
    } else
        return avl_root;

    avl_root->height = max(height(avl_root->left), height(avl_root->right)) + 1;
    int bf = getBalance(avl_root);

    if ((bf == 2) && (avl_root->left->node->val > val))
        avl_root = rightRotate(avl_root);
    else if ((bf == -2) && (avl_root->right->node->val < val))
        avl_root = leftRotate(avl_root);
    else if ((bf == 2) && (avl_root->left->node->val < val)) {
        avl_root->left = leftRotate(avl_root->left);
        avl_root = rightRotate(avl_root);
    } else if ((bf == -2) && (avl_root->right->node->val > val)) {
        avl_root->right = rightRotate(avl_root->right);
        avl_root = leftRotate(avl_root);
    }
    return avl_root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    avl_node avl_root = NULL;
    while (head) {
        avl_root = Insert(avl_root, head->val);
        head = head->next;
    }
    if (avl_root)
        return avl_root->node;
    return NULL;
}
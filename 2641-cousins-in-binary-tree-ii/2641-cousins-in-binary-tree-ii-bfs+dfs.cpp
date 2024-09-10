/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void BFS_LevelSum(TreeNode* root,vector<int> &levelSum){
        queue<TreeNode*> q;
        int n,level=0; struct TreeNode* node;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            levelSum.push_back(0);
            for(int i=0;i<n;i++){
                node = q.front();
                q.pop();
                levelSum[level] += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level++;
        }
    }
    void DFS_Replace(TreeNode* root,vector<int> &levelSum,int level){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        if(root->left && root->right){
            root->left->val = levelSum[level+1] - root->left->val - root->right->val;
            root->right->val = root->left->val;
        }
        else if(root->right)
            root->right->val = levelSum[level+1] - root->right->val;
        else
            root->left->val = levelSum[level+1] - root->left->val;
        DFS_Replace(root->left,levelSum,level+1);
        DFS_Replace(root->right,levelSum,level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        root->val = 0;
        BFS_LevelSum(root,levelSum);
        DFS_Replace(root,levelSum,0);
        return root;
    }
};
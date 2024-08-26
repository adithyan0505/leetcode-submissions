/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void recursion(Node* root,int &level,vector<vector<int>> &ret){
        if(root){
            if(level == ret.size())
                ret.push_back({root->val});
            else
                ret[level].push_back(root->val);
            int size = (root->children).size();
            for(int i = 0;i < size;i++){
                level++;
                recursion((root->children)[i],level,ret);
                level--;
            }
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        int level = 0;
        recursion(root,level,ret);
        return ret;
    }
};
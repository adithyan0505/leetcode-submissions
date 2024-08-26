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
    void recursion(Node* root,vector<int> &arr){
        if(root){
            arr.push_back(root->val);
            int size = (root->children).size();
            for(int i = 0;i < size;i++)
                recursion((root->children)[i],arr);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ret;
        recursion(root,ret);
        return ret;
    }
};
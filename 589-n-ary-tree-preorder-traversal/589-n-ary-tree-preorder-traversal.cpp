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
    // doing dfs
    void preorder(Node* root,vector<int>& ans){
        if(!root) return;
        //push back root in ans before recursive call is preorder since root is pushed first then its childrens 
        ans.push_back(root->val);
        for(int i = 0 ; i<root->children.size();i++){
            //dfs through all the children of tree 
            preorder(root->children[i],ans);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};
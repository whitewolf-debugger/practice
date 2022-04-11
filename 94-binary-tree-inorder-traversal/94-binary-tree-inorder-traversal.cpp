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
    void help(vector<int> & v, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL)
            help(v,root->left);
        v.push_back(root->val);
        if(root->right!=NULL)
            help(v,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        help(v,root);
        return v;
    }
};
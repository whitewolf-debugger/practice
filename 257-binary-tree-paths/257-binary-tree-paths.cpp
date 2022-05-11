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
    void dfs(TreeNode * root,vector<string> &ans,string str){
        // if root == NULL return
        if(root==NULL){
            return;
        }
        //if it is a leav then we add the value of leaf to string and push string in ans and terminate
        if(root->right == NULL && root->left == NULL) {
            str =str+to_string(root->val);
            ans.push_back(str);
            return;
        }
        // if it is a root then we add that value to string with ->
        str =str+to_string(root->val)+"->";
        // do dfs
        dfs(root->left,ans,str);
        dfs(root->right,ans,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str= "";
        dfs(root,ans,str);
        return ans;
    }
};
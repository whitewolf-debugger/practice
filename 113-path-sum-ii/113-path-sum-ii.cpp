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
    void dfs(TreeNode* root,vector<vector<int>>& ans,vector<int> path,int target){
        if(root == NULL) return;
        if(root->val ==target){
            path.push_back(target);
            if(root->left==NULL && root->right == NULL){
                ans.push_back(path);
            }
            else{
                dfs(root->left,ans,path,0);
                dfs(root->right,ans,path,0);
            } 
            return;
        }
        else{
            path.push_back(root->val);
            dfs(root->right,ans,path,target-root->val);
            dfs(root->left,ans,path,target-root->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root,ans,path,targetSum);
        return ans;
    }
};
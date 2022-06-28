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
    void dfs(TreeNode* root,int &ans,int level){
        //base case of dfs 
        if(!root) return;
        //if left and right of root is NULL means we are at the leaf updae the ans 
        if(root->right==NULL && root->left==NULL){
            ans = min(ans,level+1);
        }
        //dfs calls on left and right and increase the level 
        dfs(root->left,ans,level+1);
        dfs(root->right,ans,level+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        //put ans as INT_MAX since we want minimum depth;
        int ans =INT_MAX;
        int level =0;
        //do dfs 
        dfs(root,ans,level);
        //return ans 
        return ans;
    }
};
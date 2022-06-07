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
    int mod = 1e9+7;
    void dfs(TreeNode* root,int &targetSum,int &ans,vector<int> &result){
        if(root == NULL) return;
        result.push_back(root->val);
        dfs(root->left,targetSum,ans,result);
        dfs(root->right,targetSum,ans,result); 
        int sum=0;
        for(int i=result.size()-1;i>=0;i--){
            sum=(sum+(result[i]%mod))%mod;
            if(sum==targetSum){
                ans+=1;
            }
        }
        result.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans =0;
        vector<int> result;
        dfs(root,targetSum,ans,result);
        return ans;
    }
};
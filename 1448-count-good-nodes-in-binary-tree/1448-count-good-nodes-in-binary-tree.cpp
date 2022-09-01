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
    void dfs(TreeNode* root,int currMax,int &count){
        if(!root) return;
        if(root -> val >= currMax){
        
            count++;
            currMax =root -> val;
        }
        
        dfs(root -> left, currMax, count);
        dfs(root -> right, currMax, count);
    }
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        int currmax = INT_MIN;
        dfs(root,currmax,count);
        return count;
        
    }
};
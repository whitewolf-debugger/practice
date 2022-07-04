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
    int calculator(TreeNode* root ,int &ans){
        if(!root) return -1;
        int lh = calculator(root->left,ans);
        int rh = calculator(root->right,ans);
        ans = max(ans,lh+rh+2);
        return  1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        calculator(root,ans);
        return ans;
    }
};
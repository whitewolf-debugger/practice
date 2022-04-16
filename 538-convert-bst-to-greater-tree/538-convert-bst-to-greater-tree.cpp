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
    int dfs(TreeNode * root , int abovesum){
        if(root==NULL){
            return 0;
        }
        int right = dfs(root->right,abovesum);
        int left = dfs(root->left , root->val + right + abovesum);
        int sumbelow = left + right + root->val;
        root->val+= right+abovesum;
        return sumbelow;
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root,0);
        return root;
    }
};
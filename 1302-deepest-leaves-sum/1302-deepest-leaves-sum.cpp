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
    void dfs(TreeNode* root, vector<int>& deep, int depth) {
        if(!root) return;
        if(depth >= deep.size()) {
            deep.push_back(root->val);
        } else {
            deep[depth] += root->val;
        }
        
        dfs(root->left, deep, depth+1);
        dfs(root->right, deep, depth+1);
        
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<int> deeps;
        dfs(root, deeps, 0);
        return deeps.back();
    }
};


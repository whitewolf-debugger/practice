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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    void dfs(TreeNode *root,vector<int> &values,int level){
        if(root ==NULL) return;
        values[level] = max(values[level],root->val);
        dfs(root->left,values,level+1);
        dfs(root->right,values,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        int h = height(root);
        vector<int> values(h,INT_MIN);
        dfs(root,values,0);
        return values;
    }
};
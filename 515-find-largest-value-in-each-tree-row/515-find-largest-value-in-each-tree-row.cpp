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
    // finds out hte height of the tree 
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    void dfs(TreeNode *root,vector<int> &values,int level){
        //base case 
        if(root ==NULL) return;
        // max value at that index = max(values[level],root->val); where initally INT_MIN was placed
        values[level] = max(values[level],root->val);
        // increase level as we go down
        dfs(root->left,values,level+1);
        dfs(root->right,values,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        int h = height(root);
        // create vector of  size h put INT_MIN at every index
        vector<int> values(h,INT_MIN);
        //do dfs 
        dfs(root,values,0);
        return values;
    }
};
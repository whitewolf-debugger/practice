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
    TreeNode *find(TreeNode* root,int target){
        if(!root) return NULL;
        if(root -> val == target) return root;;
        TreeNode* left = find(root -> left,target);
        TreeNode* right = find(root -> right,target);
        return left == NULL ? right : left;
    }
    bool helper(TreeNode* originalroot,TreeNode* root,int k){
        if(!root) return false;
        int target = k - root -> val;
        TreeNode* searched = find(originalroot,target);
        if(searched != root && searched != NULL) return true;
        bool left = helper(originalroot,root->left,k);
        bool right = helper(originalroot,root->right,k);
        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root,root,k);
    }
};
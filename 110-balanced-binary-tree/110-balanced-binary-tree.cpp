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
    bool isBalanced(TreeNode* root) {
        int lh=0;
        int rh=0;
        if(root==NULL){
               return true;
        }
        lh = height(root->left);
        rh = height(root->right);
        return ((abs(rh-lh)<=1) && isBalanced(root->left) && isBalanced(root->right));
    }
};
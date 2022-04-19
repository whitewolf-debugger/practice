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
    bool isValid(TreeNode* root, long int lo,long int hi){
        if(!root)return true; 
        if(lo>=root->val || root->val>=hi){
            return false;
        }
        bool left = isValid(root->left,lo,root->val);
        bool right = isValid(root->right,root->val,hi);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        long int max = INT_MAX;
        long int min = INT_MIN;
        max+=1;
        min-=1;
        return isValid(root,min,max);
    }
};
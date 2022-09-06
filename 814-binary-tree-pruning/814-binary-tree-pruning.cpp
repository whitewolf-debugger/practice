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
    //checks whether the subtree contains 1 in both the left and right part
    bool containsOne(TreeNode* root){
        if(!root){
            return false;
        }
        if(root -> val == 1){
            return true;
        }
        
        bool left = containsOne(root -> left);
        bool right = containsOne(root -> right);
        return left || right ;
    }
    TreeNode* pruneTree(TreeNode* root) {
        // return empty node or null when root is null or the subtree of the current root doesnot contains 1 
        if(!root) return NULL;
        if(!containsOne(root))
           return NULL;
        
        //attatch the left and right child to the root 
        root -> left = pruneTree(root -> left);
        root -> right = pruneTree(root -> right);
        
        //return the root after attatching 
        return root;
    }
};
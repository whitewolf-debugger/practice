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
    int lo , hi;
    void traverse(TreeNode* root, int &sum) {
        if(!root) return;
        if(root -> val >= lo && root -> val <= hi){
            sum += root -> val;    
        }
        traverse(root -> left, sum);
        traverse(root -> right , sum);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0;
        lo = low;
        hi = high;
        traverse(root ,sum);
        return sum;
    }
};
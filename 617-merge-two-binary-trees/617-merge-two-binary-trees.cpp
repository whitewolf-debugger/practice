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
    //we make change in 1st tree and return its head 
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //if one of the node is null return the other node
        if(root1==nullptr) return root2;
        if(root2==nullptr) return root1;
        //else  value of node 1 is added with value at that node 2
        root1->val = root1->val+root2->val;
        //attatch left and right to the root1 
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        //return ans
        return root1;
    }
};
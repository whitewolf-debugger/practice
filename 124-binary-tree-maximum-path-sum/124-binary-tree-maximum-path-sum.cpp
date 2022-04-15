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
    int helper(TreeNode *root ,int &maxsum){
        if(root == NULL){
            return 0;
        }
        int leftsum = max(0,helper(root->left,maxsum));
        int rightsum = max(0,helper(root->right,maxsum));
        maxsum = max(maxsum,leftsum+rightsum+root->val);
        return (root->val) + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int sum =INT_MIN;
        helper(root,sum);
        return sum;
    }
};
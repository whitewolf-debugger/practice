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
    TreeNode* work(vector<int> nums,int L,int R){
        if(R<L) return NULL;
        int M =(R+L)/2;
        TreeNode * root = new TreeNode(nums[M]);
        
        root->left = work(nums,L,M-1);
        root->right = work(nums,M+1,R);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return work(nums, 0, n-1);
    }
};
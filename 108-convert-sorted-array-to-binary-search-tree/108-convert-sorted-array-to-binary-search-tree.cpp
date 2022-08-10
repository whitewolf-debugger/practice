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
        //base case if L>R then return NULL
        if(R<L) return NULL;
        //mid is (R+L) /2
        int M = (R+L)/2;
        //create root 
        TreeNode * root = new TreeNode(nums[M]);
        //create  left subtree 
        root->left = work(nums,L,M-1);
        //create right subtree 
        root->right = work(nums,M+1,R);
        
        //return true
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return work(nums, 0, n-1);
    }
};
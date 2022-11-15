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
    TreeNode* convert(vector<int> &nums,int L, int R) {
        if(L > R) return NULL;
        int mid = L + ((R - L)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = convert(nums,L,mid - 1);
        TreeNode* right = convert(nums,mid + 1, R);
        root -> left = left;
        root -> right = right;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums,0,nums.size()-1);
    }
};
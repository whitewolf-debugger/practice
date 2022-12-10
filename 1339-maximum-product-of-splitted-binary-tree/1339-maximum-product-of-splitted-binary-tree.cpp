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
    int MOD = 1e9 + 7;
    int subtreeSum(TreeNode * root) {
        if(!root) return 0;
        int leftSum = subtreeSum(root -> left);
        int rightSum = subtreeSum(root -> right);
        return root -> val + leftSum + rightSum;
    }
    
    long long getAns(TreeNode* root , long long &totalSum ,long long &ans) {
        if(!root) return 0;
        long long left = getAns(root -> left, totalSum, ans);
        long long right = getAns(root -> right, totalSum ,ans);

        long long currHalf = (root -> val + left + right) % MOD;
        long long remainingHalf = (totalSum - currHalf) % MOD;
        ans = max(ans , (currHalf * remainingHalf));
        return currHalf;
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = subtreeSum(root);

        long long ans = 0;
        getAns(root , totalSum,ans);
        return ans % MOD;

    }
};
/*



*/